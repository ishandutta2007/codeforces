#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1.5e7 +5;

int n, store=0;
int a[N], f[N];
int sieve[N], prime[N];

void preprocess()
{
	fill(sieve+2, sieve+N, 1);
	prime[2]=2;
	for(int j=2;2*j<N;j++)
	{
		sieve[2*j]=0;
		prime[2*j]=2;
	}
	for(int i=3;i<N;i+=2)
	{
		if(sieve[i])
		{
			for(int j=2;i*j<N;j++)
			{
				sieve[i*j]=0;
				prime[i*j]=i;
			}
			prime[i]=i;
		}
	}
}

int32_t main()
{
	IOS;
	preprocess();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		store=__gcd(store, a[i]);
	}
	fill(sieve, sieve+N, 0);
	for(int i=1;i<=n;i++)
	{
		int cur=a[i]/store;
		while(cur>1)
		{
			if(sieve[prime[cur]]!=i)
				f[prime[cur]]++;
			sieve[prime[cur]]=i;
			cur/=prime[cur];
		}
	}
	int ans=-1, curf=0;
	for(int i=2;i<N;i++)
	{
		if(f[i]>curf)
		{
			curf=f[i];
			ans=i;
		}
	}
	if(ans==-1)
		curf=n+1;
	cout<<n-curf;
	return 0;
}