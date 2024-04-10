#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int a[N];

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			int ct=0;
			for(int k=j;ct<i;k++)
			{
				ct++;
				a[k]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans, a[i]);
	}
	cout<<ans;
	return 0;
}