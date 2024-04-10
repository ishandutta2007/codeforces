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
int n, m;
int c[100100];
int u[100100];
vector<int> g[100100];

int dfs(int v){
	u[v] = 1;
	for(int i = 0; i< g[v].size(); i++){
		int to = g[v][i];
		if(!u[to]){
			c[v] = min(c[v], dfs(to));
		}
	}
	return c[v];
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i<=n; i++){
		scanf("%d", &c[i]);
	}
	for(int i=0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(!u[i]) ans += dfs(i);
	}
	cout << ans << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}