#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, c, ans=0;
int a[N], pref[N];
vector<int> g[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		pref[i]=pref[i-1] + (a[i]==c);
		g[a[i]].push_back(i);
	}
	ans=m[c];
	for(int i=1;i<=5e5;i++)
	{
		if(i==c || !g[i].size())
			continue;
		int l=g[i][0];
		int max_so_far=0, cur=0;
		int prev=l;
		for(auto &it:g[i])
		{	
			cur=cur + 1 - (pref[it] - pref[prev]);
			prev=it;
			if(cur<=0)
				cur=1;
			max_so_far=max(max_so_far, cur);
		}
		ans=max(ans, pref[n] + max_so_far);
	}
	cout<<ans;
	return 0;
}