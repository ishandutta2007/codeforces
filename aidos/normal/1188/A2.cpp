#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
vector<pii> g[100100];
int n;
int e[100100];
vector<pair<pii, int> > ans;

bool dfs3(int v, int p, int u, int val) {
	if(v == u) return 1;
	for(int i = 0; i  < g[v].size(); i++) {
		int to = g[v][i].f;
		int ind = g[v][i].s;
		if(to == p) continue;
		if(dfs3(to, v, u, val)) {
			e[ind] -= val;
			return 1;
		}
	}
	return 0;
}
void add(int v, int u, int val) {
	if(v != u) ans.pb(mp(mp(v, u), val));
	dfs3(v, -1, u, val);
}
pii dfs2(int v, int p) {
	pii ans = mp(-1, -1);
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		if(to == p) continue;
		pii cur = dfs2(to, v);
		if(ans.f == -1) ans = cur;
		else ans.s = cur.f;
	}
	if(ans.f == -1) return mp(v, v);
	return ans;
	
}
void dfs(int v, int p = -1) {
	vector<pair<pii, pii> > G;
	for(int i=0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		int val = e[g[v][i].s];
		if(to == p) continue;
		dfs(to, v);
		pii a = dfs2(to, v);
		pii b = dfs2(v, to);
		add(a.f, b.f, val/2);
		add(a.s, b.s, val/2);
		add(a.f, a.s, -val/2);
		add(b.f, b.s, -val/2);
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[i] = z;
		g[x].pb(mp(y, i));
		g[y].pb(mp(x, i));
	}
	for(int i = 1; i <= n; i++) {
		if(g[i].size() != 2) continue;
		if(e[g[i][0].s] != e[g[i][1].s]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	int v = -1;
	vector<int> li;
	for(int i = 1; i <= n; i++) {
		if(g[i].size() >= 3) v = i;
		if(g[i].size() == 1) li.pb(i);
	}
	if(v == -1) {
		cout << 1 << "\n";
		cout << li[0] << " " << li[1] << " " << e[g[1][0].s] << "\n";
		return;
	}
	
	dfs(v);
	
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i].f.f << " "<<ans[i].f.s << " "<< ans[i].s<<"\n";
	
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}