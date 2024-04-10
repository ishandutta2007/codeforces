#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, s, ans=-1;
int x[N], y[N];

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		int cur=x[i] + (y[i]>0);
		if(s>=cur && y[i])
			ans=max(ans, 100-y[i]);
		else if(s>=cur && !y[i])
			ans=max(ans, 0LL);
	}
	cout<<ans;
	return 0;
}