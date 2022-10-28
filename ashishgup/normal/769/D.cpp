#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, ans=0;
int a[N], f[N], bits[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=0;i<(1<<14);i++)
		bits[i]=__builtin_popcount(i);
	for(int i=0;i<=1e4;i++)
	{
		for(int j=0;j<=1e4;j++)
		{
			if(bits[i^j]==k)
			{
				if(i!=j)
					ans+=f[i]*f[j];
				else
					ans+=(f[i]*(f[i]-1));
			}
		}
	}
	ans/=2;
	cout<<ans;
	return 0;
}