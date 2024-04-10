#include <iostream>
#include <cmath>
 
#define INF 1000000000
 
int main()
{
	int N;
	std::cin >> N;
 
	int seq[N];
	for(int i = 0; i < N; i++)
		std::cin >> seq[i];
 
	long long answer = INF;
	for(int i = 1; i <= N; i++)
	{
		long long update = 0;
		for(int j = 1; j <= N; j++)
			update += 2*seq[j-1]*(abs(j-i) + abs(j-1) + abs(i-1));
		answer = std::min(update, answer);
	}
 
	std::cout << answer;
 
	return 0;
}