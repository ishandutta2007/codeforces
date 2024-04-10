#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, x, y, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	if(x>y)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=(a[i]<=x);
	}
	ans=(ans+1)/2;
	cout<<ans;
	return 0;
}