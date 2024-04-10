#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, mx=0, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx, a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=mx)
			continue;
		int j;
		for(j=i;j<=n;j++)
		{
			if(a[j]!=a[i])
				break;
		}
		ans=max(ans, j-i);
		i=j-1;
	}
	cout<<ans;
	return 0;
}