#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int a[N], b[N], c[N];

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<=1000;i++)
	{
		c[i]=i;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=b[i];j>=a[i];j--)
		{
			c[j]=max(c[j], max(b[i], c[b[i]]));
		}
	}
	if(c[0]>=m)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}