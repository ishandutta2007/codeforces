#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int chapters[n];
	for(int i = 0; i < n; i++)
		std::cin >> chapters[i] >> chapters[i];
	
	int k;
	std::cin >> k;
	
	int answer = 0;
	for(int i = 0; i < n; i++)
		if(chapters[i] >= k)
			answer++;
	
	std::cout << answer;
	
	return 0;
}