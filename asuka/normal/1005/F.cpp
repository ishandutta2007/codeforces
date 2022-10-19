#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, k, dep[N];
bool vis[N], used[N];
queue<int> q;
vector<pii> e[N];
VI fa[N];
void bfs() {
	q.push(1);
	vis[1] = 1;
	dep[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto V : e[u]) {
			int v = V.fi, id = V.se;
			if(dep[v] >= dep[u] + 1) {
				dep[v] = dep[u] + 1;
				if(!vis[v]) q.push(v);
				vis[v] = 1;
				fa[v].pb(id);
			}
		}
	}
}
int tot;
vector<string> ans;
void dfs(int u) {
	if(tot >= k) return;
	if(u == n + 1) {
		tot++;
		string tmp;
		rep(i, 1, m) tmp += '0' + used[i];
		ans.pb(tmp);
	}
	for(auto v : fa[u]) {
		used[v] = 1;
		dfs(u + 1);
		used[v] = 0;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].pb(mp(v, i));
		e[v].pb(mp(u, i));
	}
	memset(dep, 0x3f, sizeof dep);
	bfs();
	dfs(2);
	cout << SZ(ans) << endl;
	for(auto x : ans) cout << x << endl;
	return 0;
}