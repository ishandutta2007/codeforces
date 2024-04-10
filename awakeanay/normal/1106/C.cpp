#include <iostream>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	
	int seq[N];
	for(int i = 0; i < N; i++)
		std::cin >> seq[i];
	
	std::sort(seq, seq + N);
	
	long long answer = 0;
	for(int i = 0; i < N/2; i++)
		answer += (seq[i]+seq[N-1-i])*(seq[i]+seq[N-1-i]);
	
	std::cout << answer;
	
	return 0;
}