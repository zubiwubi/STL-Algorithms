/*Assignment 4: STL Algorithms
Written by Zubaydah Koelemeij
06/12/2022*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

int main() 

{
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	/* Gebruik functies uit <algorithm> en <functional> om(steeds vanuit een ORIGINELE copie van deze vector).
	
	1) De vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na. */
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		/* 2) Alle elementen UPPERCASE te maken.*/
		std::vector<std::string>::iterator it = colours.begin();

		for (auto it = colours.begin(); it != colours.end(); it++)
		{
			for (char& c : *it)
			{
				c = toupper(c);
				std::cout << c;
			}

			if (it != colours.end() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		/* 3) Alle dubbele te verwijderen */
		auto rememberIt = colours.begin();
		for (auto it = colours.begin(); it != colours.end(); it++)
		{
			for (auto it2 = colours.begin(); it2 != colours.end(); it2++)
			{
				if (*it == *it2 && it != it2)
				{
					rememberIt = it;
				}
			}

			if (rememberIt != colours.begin())
			{
				it = colours.erase(it);
				rememberIt = colours.begin();
			}

			if (it != colours.end() - 1)
			{
				std::cout << *it << ", ";
			}
			else std::cout << *it;
		}
		std::cout << std::endl;
	}

	/* Gebruik functies uit <algorithm> en <functional> om(steeds vanuit een ORIGINELE copie van deze vector) */
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

		/* 1) Alle negatieve elementen te verwijderen. */
		auto rememberIt = numbers.begin();
		for (auto it = numbers.begin(); it != numbers.end(); it++)
		{
			if (*it < 0)
			{
				rememberIt = it;
			}

			if (rememberIt != numbers.begin())
			{
				it = numbers.erase(it);
				rememberIt = numbers.begin();
			}

			if (it != numbers.end() - 1)
			{
				std::cout << *it << ", ";
			}
			else std::cout << *it;
		}
		std::cout << std::endl;
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		/* 2) Voor alle elementen te bepalen of ze even of oneven zijn */
		for (auto it = numbers.begin(); it != numbers.end(); it++)
		{
			((int)*it == *it) ? (((int)(*it) % 2 == 0) ? std::cout << *it << " is even" : std::cout << *it << " is odd") : std::cout << *it << " has decimals";

			if (it != numbers.end() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		/* 3) de som, het gemiddelde, en het product van alle getallen te berekenen */
		std::cout.precision(std::numeric_limits<double>::digits10);
		std::cout << "som: " << std::accumulate(numbers.begin(), numbers.end(), 0.0) << std::endl;
		std::cout << "gemiddelde: " << std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size() << std::endl;
		std::cout << "product: " << std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());
	}

	return 0;
};