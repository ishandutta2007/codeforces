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

using namespace std;

int mx1[300100];
int mx2[300300];
int dp[300300];
int ans[300300];
vector<int> g[600300], gg[600600];
int id[600300];
int sz = 1;
int q;
int n;
int tout[300300];
int p[300300];
int tin[300300];
int timer = 0;
int li[300300];
pii t[4 * 300300];
pii combine(pii a, pii b){
	if(a.f > b.f) return b;
	if(a.f < b.f) return a;
	return mp(a.f, max(a.s, b.s));
}
pii get(int v, int l, int r, int tl, int tr){
	if(tl > tr) return mp(inf, -1);
	if(l == tl && tr == r) return t[v];
	int mid = (l + r) >> 1;
	return combine(get(v * 2, l, mid, tl, min(tr, mid)), get(v * 2+ 1, mid + 1, r, max(tl, mid +1), tr));
}
void build(int v, int l, int r){
	if(l == r){
		t[v] = mp(dp[li[l]], li[l]);
	}
	else{
		int mid = (l+r)>>1;
		build(v * 2, l, mid);
		build(v * 2 + 1, mid + 1, r);
		t[v] = combine(t[v * 2] ,t[v * 2+1]);
	}
}
void upd(int v, int l, int r, int pos, int val){
	if(l == r){
		t[v].f = val;
	}else{
		int mid = (l+r) >> 1;
		if(mid >= pos) upd(v * 2, l, mid, pos, val);
		else upd(v * 2+1, mid + 1, r, pos, val);
		t[v] = combine(t[v *2], t[v *2+1]);
	}
}

void dfs(int v, int pa){
	p[v] = pa;
	dp[v] = 1;
	li[timer] = v;
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to != pa){
			dfs(to, v);
			dp[v] += dp[to];
		}
	}
	tout[v] = timer-1;
}
void dfs2(int v, int pa){
	ans[v] = -1;
	bool ok = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to != pa){
			dfs2(to, v); 
			if(dp[to]+dp[to] > dp[v]) ok = 0;
		}
	}
	
	if(ok){
		ans[v] = v;
		return;
	}
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to != pa){
			if(ans[v] == -1 || dp[v] - dp[ans[v]] > dp[v] - dp[ans[to]]) ans[v] = ans[to];
		}
	}
//	upd(1, 0, n-1, tin[v], dp[v]);

	pii pos = get(1, 0, n-1, tin[v], tout[v]);
	while(pos.f + pos.f <= dp[v]){
		upd(1, 0, n-1, tin[pos.s], inf);

		if(p[pos.s] != v && (ans[v] == -1 || dp[v] - dp[ans[v]] > dp[v] - dp[p[pos.s]]) ) ans[v] = p[pos.s];
		pos=get(1, 0, n-1, tin[v], tout[v]);
	}
}

void solve(){
	scanf("%d %d", &n, &q);
	for(int i = 2, x; i <= n; i++){
		scanf("%d", &x);
		g[i].pb(x);
		g[x].pb(i);
	}
	dfs(1, 0);
	build(1, 0, n-1);
	dfs2(1, 0);
	for(int i = 0, x; i < q; i++){
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}