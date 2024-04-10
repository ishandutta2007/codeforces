#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e7+5;

int n;
int a[N], f[N];
bool sieve[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	fill(sieve, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=2;i*j<N;j++)
			{
				f[i]+=f[i*j];
				sieve[i*j]=0;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!sieve[i])
			f[i]=0;
		f[i]+=f[i-1];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a, b;
		cin>>a>>b;
		b=min(b, N-1);
		a=min(a, N);
		int ans=f[b] - f[a-1];
		cout<<ans<<endl;
	}
}