#include <iostream>
#include <vector>

#define MOD 998244353

int main()
{
	long long n, k;
	std::cin >> n >> k;
	
	long long exp[n+1];
	exp[0] = 1;
	for(int i = 1; i <= n; i++)
		exp[i] = (exp[i-1]*(k-1))%MOD;
	
	long long same[n];
	long long diff[n];
	same[0] = 0;
	diff[0] = 1;
	same[1] = k-1;
	diff[1] = std::max((long long)0, k-2);
	
	for(int i = 2; i < n; i++)
	{
		same[i] = (k*exp[i-1])%MOD - 2*same[i-1] - same[i-2];
		diff[i] = (k*exp[i-1])%MOD - 2*diff[i-1] - diff[i-2];
		while(same[i] < 0)
			same[i] += MOD;
		while(diff[i] < 0)
			diff[i] += MOD;
	}
	
	std::vector<int> seq[2];
	for(int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		seq[i%2].push_back(a);
	}
	
	long long answer = 1;
	for(int m = 0; m < 2; m++)
	{
		int i = 0;
		int count = 0;
		while(seq[m][i] == -1 && i < seq[m].size())
		{
			count++;
			i++;
		}
		
		if(i == seq[m].size())
			answer = (answer*k*exp[count-1])%MOD;
		else
			answer = (answer*exp[count])%MOD;
		
		int last = -1;
		count = 0;
		for(; i < seq[m].size(); i++)
		{
			if(last == -1)
				last = seq[m][i];
			else if(seq[m][i] == -1)
				count++;
			else
			{
				if(seq[m][i] == last)
				{
					answer = (answer*same[count])%MOD;
				}
				else
					answer = (answer*diff[count])%MOD;
				last = seq[m][i];
				count = 0;
			}
		}
		
		if(count > 0)
			answer = (answer*exp[count])%MOD;
	}
	
	std::cout << answer;
	
	return 0;
}