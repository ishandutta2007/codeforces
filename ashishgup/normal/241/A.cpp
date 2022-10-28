#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, k, fuel=0, ans=0, curmax=0;
int d[N], s[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	curmax=s[1];
	for(int i=1;i<=n;i++)
	{
		fuel+=s[i];
		curmax=max(curmax, s[i]);
		while(fuel<d[i])
		{
			fuel+=curmax;
			ans+=k;
		}
		fuel-=d[i];
		ans+=d[i];
	}
	cout<<ans;
	return 0;
}