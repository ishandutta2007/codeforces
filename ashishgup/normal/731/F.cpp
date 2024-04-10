#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

int n, ans=0;
int a[N], sieve[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sieve[a[i]]++;
	}
	for(int i=1;i<N;i++)
		sieve[i]+=sieve[i-1];
	for(int i=1;i<N;i++)
	{
		if(!(sieve[i]-sieve[i-1]))
			continue;
		int cur=0;
		for(int j=2;i*j<N;j++)
		{
			int elems=sieve[i*j-1]-sieve[i*(j-1)-1];
			cur+=elems*(i*(j-1));
		}
		ans=max(ans, cur);
	}
	cout<<ans;
	return 0;   
}