#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	int seq[N];
	for(int i = 0; i < N; i++)
		std::cin >> seq[i];
	
	int ans = 1;
	int second = -1;
	for(int i = 1; i < N; i++)
	{
		if(seq[i] != seq[0])
		{
			ans = i;
			if(second == -1)
				second = i;
		}
		else
			if(second != -1)
				ans = std::max(ans, i - second);
	}
	
	std::cout << ans;
	
	return 0;
}