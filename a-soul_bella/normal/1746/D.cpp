#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int inf=1e18;
vector<int> e[200005];
int a[200005];
pair<int,int> dfs(int u,int k)
{
	if(e[u].size()==0) return {a[u]*k,a[u]*(k+1)};
	vector<pair<int,int> > s;
	for(auto v:e[u])
		s.push_back(dfs(v,k/e[u].size()));
	int rtn=a[u]*k;
	for(auto t:s) rtn+=t.first;
	for(int i=0;i<s.size();i++) s[i].second-=s[i].first,swap(s[i].first,s[i].second);
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
//	cout << u << " " << k << " " << e[u].size() << " " << k%e[u].size() << " " << s[0].first << "!!\n";
	for(int i=0;i<k%e[u].size();i++) rtn+=s[i].first;
	return {rtn,rtn+s[k%e[u].size()].first+a[u]};
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=0;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++)
		{
			int x;
			cin >> x;
			e[x].push_back(i);
		}
		for(int i=1;i<=n;i++)
			cin >> a[i];
		cout << dfs(1,k).first << "\n";
	}
	return 0;
}