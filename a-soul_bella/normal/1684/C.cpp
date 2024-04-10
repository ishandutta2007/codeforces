#include <bits/stdc++.h>
using namespace std;
int n,m;
inline pair<int,int> cal(vector <int> v)
{
	vector <int> V=v;
	sort(V.begin(),V.end());
	if(v==V) return {0,0};
	vector <int> s;
	for(int i=0;i<v.size();i++)
		if(v[i]!=V[i]) s.push_back(i);
	if(s.size()>=3) return {-1,-1};
	return {s[0]+1,s[1]+1};
}
inline pair<int,int> add(pair<int,int> x,pair<int,int> y)
{
	if(x==make_pair(-1,-1)) return x;
	if(y==make_pair(-1,-1)) return y;
	if(x==make_pair(0,0)) return y;
	if(y==make_pair(0,0)) return x;
	if(x!=y) return {-1,-1};
	return x;
}
vector <int> qwq[200005];
inline bool check(pair<int,int> x)
{
	for(int i=1;i<=n;i++)
	{
		swap(qwq[i][x.first-1],qwq[i][x.second-1]);
		if(cal(qwq[i])!=make_pair(0,0)) return 0; 
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		pair<int,int> ans={0,0};
		for(int i=1;i<=n;i++)
		{
			vector <int> v;
			for(int j=1;j<=m;j++)
			{
				int c;
				cin >> c;
				v.push_back(c);
			}
			ans=add(ans,cal(v));
			qwq[i].swap(v);
		}
		if(ans.first==0) cout << "1 1\n";
		else if(ans.first==-1||!check(ans)) cout << "-1\n";
		else cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}