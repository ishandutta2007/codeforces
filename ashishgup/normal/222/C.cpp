#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e7+5;

int n, m;
int sieve[N], prime[N];
int a[2][N], f[2][N];

void precompute()
{
	fill(sieve+2, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=0;
				prime[i*j]=i;
			}
		}
	}
}

void work(int idx, int sz)
{
	for(int i=1;i<=sz;i++)
	{
		int cur=a[idx][i];
		while(cur>1)
		{
			f[idx][prime[cur]]++;
			cur/=prime[cur];
		}
	}
}

void print(int idx, int sz)
{
	for(int i=1;i<=sz;i++)
	{
		int cur=a[idx][i];
		int ans=1;
		while(cur>1)
		{
			if(f[idx][prime[cur]])
			{
				f[idx][prime[cur]]--;
				ans*=prime[cur];
			}
			cur/=prime[cur];
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[0][i];
	for(int i=1;i<=m;i++)
		cin>>a[1][i];
	work(0, n);
	work(1, m);
	for(int i=1;i<N;i++)
	{
		int storemin=min(f[0][i], f[1][i]);
		f[0][i]-=storemin;
		f[1][i]-=storemin;
	}
	cout<<n<<" "<<m<<endl;
	print(0, n);
	print(1, m);
	return 0;
}