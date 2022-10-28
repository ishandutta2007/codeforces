#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k;
int a[N], pref[N];
map<int, int> m, vis;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]^a[i];
		m[pref[i]]++;
	}
	m[0]++;
	int ans=n*(n+1)/2;
	int complement=(1LL<<k)-1;
	for(auto &it:m)
	{	
		if(vis[it.first])
			continue;
		vis[it.first]=1;
		vis[it.first^complement]=1;
		int cur=it.second;
		cur+=m[it.first^complement];
		int l=cur/2;
		int r=(cur+1)/2;
		ans-=(l*(l-1))/2;
		ans-=(r*(r-1))/2;
	}
	cout<<ans;
	return 0;
}