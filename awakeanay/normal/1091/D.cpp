#include <iostream>

#define MOD 998244353

int main() 
{
	int N;
	std::cin >> N;
	
	long long fac[N+1];
	long long rfac[N+1];
	
	fac[0] = 1;
	rfac[0] = 1;
	
	for(int i = 1; i <= N; i++)
	{
		fac[i] = (i*fac[i-1] + MOD) % MOD;
		rfac[i] = (rfac[i-1]*(N+1-i) + MOD) % MOD;
	}
	
	long long answer = fac[N];
	
	for(int i = 1; i < N; i++)
	{
		answer = (answer + rfac[i]*(fac[N-i] - 1) + MOD)%MOD;
	}
	
	std::cout << answer;
	
	return 0;
}