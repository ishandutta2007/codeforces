#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool P[100500];
long a[500][500];
vector < int > primes;

int main()
{
	for(int i=2;i<100500;i++)
	{
		if(!P[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<100500;j+=i)
			{
				P[j] = 1;
			}
		}
	}

	int n,m;

	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%ld",&a[i][j]);
		}
	long long ans = 100000LL*500LL*500LL+25LL;

	for(int i=0;i<n;i++)
	{
		long long curr_sum = 0;
		for(int j=0;j<m;j++)
		{
			//int t=*upper_bound(primes.begin(),primes.end(),a[i][j]);
			curr_sum += *lower_bound(primes.begin(),primes.end(),a[i][j])-a[i][j];
		}
		ans = min(ans,curr_sum);
	}
	for(int i=0;i<m;i++)
	{
		long long curr_sum = 0;
		for(int j=0;j<n;j++)
		{
			curr_sum += *lower_bound(primes.begin(),primes.end(),a[j][i])-a[j][i];
		}
		ans = min(ans,curr_sum);
	}
	cout << ans;
		


	return 0;
}