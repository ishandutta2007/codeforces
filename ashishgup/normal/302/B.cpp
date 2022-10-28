#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int c[N], t[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>t[i];
		pref[i]=pref[i-1] + c[i]*t[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		auto it=lower_bound(pref+1, pref+n+1, x) - pref;
		cout<<it<<endl;
	}
	return 0;
}