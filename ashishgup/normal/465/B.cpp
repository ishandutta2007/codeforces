#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, ans=-1;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			continue;
		ans+=2;
		while(i+1<=n && a[i+1]==1)
		{
			ans++;
			i++;
		}
	}
	ans=max(0LL, ans);
	cout<<ans;
	return 0;
}