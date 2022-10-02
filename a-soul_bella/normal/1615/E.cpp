#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> e[200005];
int cnt=0;
priority_queue <signed> s[200005];
inline void dfs(int u,int f)
{
	int mx=0,pos=0;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dfs(v,u);
		if(s[v].size()>mx)
			mx=s[v].size(),pos=v;
	}
	if(pos) swap(s[u],s[pos]);
	for(auto v:e[u])
	{
		if(v==f||v==pos) continue;
		while(!s[v].empty())
		{
			int t=s[v].top();
			++cnt;
			s[v].pop();
			s[u].push(t);
		}
	}
	if(s[u].empty()) s[u].push(0);
	int x=s[u].top();
	s[u].pop(),s[u].push(x+1);
}
signed main(int argc, char** argv) {
	int T;
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int w=0;
	int ans=1e18;
	if(k>=s[1].size())
	{
		ans=-1e18;
		for(int i=s[1].size();i<=k;i++)
			ans=max(ans,(n-i)*i);
		cout << ans;
		return -0;
	}
/*	cout << s[1].size() << "\n";
	while(!s[1].empty())
	{
		cout << s[1].top() << "\n";
		s[1].pop();
	}*/
	for(int i=1;i<=k;i++)
	{
		if(s[1].empty()) break;
		w+=s[1].top(),s[1].pop();
	}
	for(int i=0;i<=n-w;i++)
		ans=min(ans,(n-i-k)*(k-i));
	cout << ans;
	return 0;
}
/*
13 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
*/