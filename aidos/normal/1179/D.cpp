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

ll ans;
vector<int> g[500500];
int n;
int sz[500500];

ll dfs(int v, int pa){
	sz[v] = 1;
	vector<pll> G;
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if(to==pa) continue;
		ll dd = dfs(to, v);
		sz[v] += sz[to];
		G.pb(mp(sz[to], dd));
	}
	if(G.size() == 0) return 0;
	sort(all(G));
	for(int i = 0; i < G.size(); i++) {
		ll ss = n-G[i].f;
		ans = min(ans, G[i].s + ss * (ss-1)/2);
	}
	vector<pll> A;
	for(int i = 0; i < G.size(); i++){
		if(A.size() == 0 || A.back().f != G[i].f) A.pb(G[i]);	
	}
	for(int i = 1; i < G.size(); i++) {
		ll ss = n - G[i].f - G[i-1].f;
		ans = min(ans, ss * (ss-1)/2 + G[i].s + G[i-1].s);
	}
	for(int i = 0; i < A.size(); i++) {
		for(int j = i + 1; j < A.size(); j++) {		
			ll ss = n - A[i].f - A[j].f;
			ans = min(ans, ss * (ss-1)/2 + A[i].s + A[j].s);
		}
	}
	ll cur = (1ll<<50);
	for(int i = 0; i < G.size(); i++) {
		ll k = sz[v] - G[i].f;
		cur = min(cur, (k * (k-1)/2) + G[i].s);
	}
	return cur;
}

void solve(){
	scanf("%d", &n);
	for(int i = 1;i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	ans = n * (n-1ll)/2;
	dfs(1, 0);
	cout << n * 1ll * (n-1) - ans << "\n";
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