///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 5'010;

 array<vector<int>, N>   A
;array<pii,         N>   O
;array<vector<int>, N>   T
;                     /* If you lose you die.
                       * If you win you live.
                       * If you don't fight you can't win.
                       * Fight! Fight! */

pii E[N];
int dis[N][N];
bool notsink[N];
int col[N];
int mincyc[N];
int n, m;

vector<int> ord;
bool vis[N];
void dfs1(int v)
{
	vis[v] = 1;
	for(int u : A[v])
		if(!vis[u])
			dfs1(u);
	ord.push_back(v);
}
void dfs2(int v, int c)
{
	col[v] = c;
	vis[v] = 1;
	for(int u : T[v])
		if(!vis[u])
			dfs2(u,c);
}

void bfs(int s)
{
	queue<int> q;
	fill(dis[s], dis[s]+N, N);
	dis[s][s] = 0;
	q.push(s);
	while(q.size()){
		int v = q.front(); q.pop();
		for(int u : A[v]){
			if(dis[s][u] == N){
				dis[s][u] = dis[s][v]+1;
				q.push(u);
			}
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		O[i]={v, u};
		T[u].push_back(v);
	}
	Loop(i,0,n) bfs(i);
	memset(vis,0,sizeof vis);
	Loop(i,0,n) if(!vis[i]) dfs1(i);
	int cnt = 0;
	memset(vis,0,sizeof vis);
	reverse(ord.begin(), ord.end());
	Loop(i,0,n) if(!vis[ord[i]]) dfs2(ord[i], cnt++);
	fill(mincyc, mincyc+N, N);
	Loop(i,0,m){
		auto [v, u] = O[i];
		if(col[v] != col[u]) notsink[col[v]] = 1;
		else mincyc[col[v]] = min(mincyc[col[v]], dis[u][v]+1);
	}
	ll ans = n;
	Loop(i,0,cnt)
		if(!notsink[i] && mincyc[i] != N)
			ans += mincyc[i]*998+1;
	cout << ans << '\n';
}