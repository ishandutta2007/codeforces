#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> G[1005],D;
vector<pii> cent,edge;
bitset<1005> vis;
int ans,lon[1005],t;

void dfs(int u,int f)
{
	vis[u]=1,D.pb(u);
	for(int i:G[u])
		if(i!=f)
			dfs(i,u);
}

void dfs2(int u,int f,int d)
{
	lon[t]=max(lon[t],d);
	for(int i:G[u])
		if(i!=f)
			dfs2(i,u,d+1);
}

int main()
{jizz
	int n,m,a,b,mi;
	cin >> n >> m;
	while(m--)
		cin >> a >> b,G[a].pb(b),G[b].pb(a);
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			D.clear(),dfs(i,i),mi=n;
			for(int j:D)
				t=j,dfs2(t,t,0),mi=min(lon[t],mi);//,cout << "(" << j << "," << lon[j] << ") ";
			//ET;
			for(int j:D)
				if(lon[j]==mi)
				{
					cent.pb(MP(lon[j],j));
					break;
				}
		}
	sort(ALL(cent));
	for(int i=0;i+1<cent.size();++i)
		edge.pb(MP(cent[i].S,cent.back().S)),G[cent[i].S].pb(cent.back().S),G[cent.back().S].pb(cent[i].S);
	for(int i=1;i<=n;++i)
		t=i,dfs2(i,i,0);
	cout << *max_element(lon+1,lon+n+1) << "\n";
	for(auto i:edge)
		cout << i.F << " " << i.S << "\n";
}