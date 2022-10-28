#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=1e10;
char a[N];
int x[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]=='R' && a[i]=='L')
			ans=min(ans, x[i]-x[i-1]);
	}
	ans/=2;
	if(ans>1e9)
		ans=-1;
	cout<<ans;
	return 0;
}