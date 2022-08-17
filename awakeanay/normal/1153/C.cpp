#include <iostream>

int main()
{
	int l;
	std::cin >> l;
	
	std::string s;
	std::cin >> s;
	
	bool poss = true;
	
	int diff = 0;
	int open = 0;
	for(int i = 0; i < l; i++)
		open += (s[i] == '(');
	
	for(int i = 0; i < l; i++)
	{
		if(s[i] == '?')
		{
			if(open < l/2)
			{
				s[i] = '(';
				open++;
			}
			else
				s[i] = ')';
		}
	}
	
	for(int i = 0; i < l; i++)
	{
		if(diff <= 0 && i > 0)
			poss = false;
		if(s[i] == '(')
			diff++;
		else
			diff--;
	}
	
	if(poss && (diff == 0))
		std::cout << s;
	else
		std::cout << ":(";
	
	return 0;
}