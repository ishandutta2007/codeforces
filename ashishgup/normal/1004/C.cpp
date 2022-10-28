#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N], vis[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		m[a[i]]--;
		if(m[a[i]]==0)
			m.erase(a[i]);
		if(vis[a[i]])
			continue;
		vis[a[i]]=1;
		ans+=m.size();
	}
	cout<<ans;
	return 0;
}