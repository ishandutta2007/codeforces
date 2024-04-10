#include <iostream>
#include <string>

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
	{
		std::string a, b;
		std::cin >> a >> b;
		
		bool poss = true;
		
		int i = 0, j = 0;
		char last = '#';
		for(int i = 0; i < a.length(); i++)
		{
			if(j >= b.length())
			{
				poss = false;
				break;
			}
			
			while(b[j] != a[i])
			{
				if(j+1 >= b.length() || b[j] != last)
				{
					poss = false;
					break;
				}
				j++;
			}
			
			if(!poss)
				break;
			
			last = a[i];
			j++;
		}
		
		while(j < b.length())
		{
			if(b[j] != last)
				poss = false;
			j++;
		}
		
		if(poss)
			std::cout << "YES";
		else
			std::cout << "NO";
		std::cout << std::endl;
	}
	
	return 0;
}