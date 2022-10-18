#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i);
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET}
using namespace std;

int d[1001][1001],yes[1001][1001];
queue<pair<int,int>> q;
vector<int> child[1001];
bitset<1001> vis;

int main()
{
	int n,m,s,t,a,b,ans=0,i,j;
	cin >> n >> m >> s >> t;
	while(m--)
		cin >> a >> b,child[a].pb(b),child[b].pb(a),yes[a][b]=yes[b][a]=1;
	for(i=1;i<=n;++i)
	{
		vis.reset(),vis[i]=1,q.push({i,0});
		while(!q.empty())
		{
			auto tmp=q.front();
			q.pop();
			d[i][tmp.F]=tmp.S;
			for(int x:child[tmp.F])
				if(!vis[x]) vis[x]=1,q.push({x,tmp.S+1});
		}
	}
	//for(i=1;i<=n;ET,++i)
	//	for(j=1;j<=n;++j)
	//		cout << d[i][j] << " ";
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			if(!yes[i][j] && d[s][i]+d[j][t]+1>=d[s][t] && d[s][j]+d[i][t]+1>=d[s][t]) ++ans;//,cout << i << " " << j << "\n";
	cout << ans << "\n";
}