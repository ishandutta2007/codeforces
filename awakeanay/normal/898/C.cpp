#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool isSuffix(std::string x, std::string y)
{
	int a = x.size();
	int b = y.size();
	
	if(a > b)
		return false;
	
	for(int i = 0; i < x.size(); i++)
	{
		if(x.at(x.size()-i-1) != y.at(y.size()-i-1))
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	int N;
	std::cin >> N;
	
	std::unordered_map<std::string, std::vector<std::string>> people;
	
	for(int i = 0; i < N; i++)
	{
		//std::cout << "Size now: " << people.size() << " " << i << std::endl;
		
		std::string name;
		std::cin >> name;
		
		int count;
		std::cin >> count;
		
		for(int j = 0; j < count; j++)
		{
			std::string input;
			std::cin >> input;
			
			bool push = true;
			for(int k = 0; k < people[name].size(); k++)
			{
				if(isSuffix(input, people[name][k]))
				{
					push = false;
				}
				else if(isSuffix(people[name][k], input))
				{
					people[name].erase(people[name].begin() + k);
					k--;
				}
			}
			
			if(push)
			{
				people[name].push_back(input);
			}
		}
	}
	
	std::unordered_map<std::string, std::vector<std::string>>::iterator it;
	std::cout << people.size();
	for(it = people.begin(); it != people.end(); ++it)
	{
		std::cout << std::endl;
		std::cout << it->first << " ";
		std::cout << it->second.size() << " ";
		for(int i = 0; i < it->second.size(); i++)
		{
			std::cout << it->second[i] << " ";
		}
	}
	
	return 0;
}