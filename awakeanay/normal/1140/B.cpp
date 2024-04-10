#include <iostream>
int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
	{
		int n;
		std::cin >> n;
		
		char seq[n];
		for(int i = 0; i < n; i++)
			std::cin >> seq[i];
		
		int answer = 100;
		for(int i = 0; i < n; i++)
			if(seq[i] == '>' || seq[n-1-i] == '<') answer = std::min(answer, i);
		
		std::cout << answer << std::endl;
	}
	
	return 0;
}