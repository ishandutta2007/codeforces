#include <iostream>

#define INF 100000000000000

int main()
{
	int N;
	long long S;
	std::cin >> N >> S;
	
	long long min = INF;
	long long seq[N];
	for(int i = 0; i < N; i++)
	{
		std::cin >> seq[i];
		min = std::min(min, seq[i]);
	}
	
	for(int i = 0; i < N; i++)
		S -= seq[i] - min;
	
	if(S <= 0)
		std::cout << min;
	else if(S > min*N)
		std::cout << -1;
	else if(S%N == 0)
		std::cout << min - S/N;
	else
		std::cout << min - S/N - 1;
	
	return 0;
}