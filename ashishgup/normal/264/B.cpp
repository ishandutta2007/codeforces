#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, finans=0;
int a[N], ans[N], sieve[N], countprime[N];
vector<int> primes[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i]=1;
	}
	for(int i=2;i<=1e5;i++)
		sieve[i]=1;
	for(int i=2;i<=1e5;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<=1e5;j++)
			{
				primes[i*j].push_back(i);
				sieve[i*j]=0;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(auto it:primes[a[i]])
			ans[i]=max(ans[i], countprime[it]+1);
		for(auto it:primes[a[i]])
			countprime[it]=max(countprime[it], ans[i]);
		finans=max(ans[i], finans);
	}
	cout<<finans;
}