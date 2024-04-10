#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0;
int a[N], b[N], vis[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		v.push_back(a[b[i]]);
		vis[b[i]]=1;
	}
	sort(v.rbegin(), v.rend());
	for(int i=1;i<=n;i++)
		if(!vis[i])
			ans+=a[i];
	for(auto &it:v)
		ans+=max(it, ans);
	cout<<ans;
	return 0;
}