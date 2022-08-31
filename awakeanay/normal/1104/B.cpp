#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string s;
	std::cin >> s;
	
	std::stack<int> sta;
	int counter = 0;
	
	for(int i = 0; i < s.length(); i++)
	{
		if(!sta.empty())
		{
			if(s[i] == sta.top())
			{
				//std::cout << sta.top();
				sta.pop();
				counter++;
			}
			else
				sta.push(s[i]);
		}
		else
			sta.push(s[i]);
	}
	
	if(!(counter%2))
		std::cout << "No";
	else
		std::cout << "Yes";
}