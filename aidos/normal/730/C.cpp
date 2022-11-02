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
const int N = (int)5005;

using namespace std;
struct store {
	int v, k, p;
	bool operator <(const store &s) const {
		return p < s.p;
	}
};
vector<int> g[N];
store a[N];
int n, m, k, qn, d[N][N];
int q[N+N];

void bfs(int v, int d[]) {
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	int l = 0, r = 0;
	d[v] = 0;
	q[r++] = v;
	while (l < r) {
		int v = q[l++];
		for(int i = 0; i < g[v].size(); i++) {
			int u = g[v][i];
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q[r++] = u;
			}
		}
	}
}

bool ok(int T, int v, int K, int C) {
	ll res = 0;
	for (int i = 1; i <= k; i++) {
		if (d[a[i].v][v] > T) continue;
		int cnt = min(K, a[i].k);
		K -= cnt;
		res += (ll)cnt * a[i].p;
	}
	if (K > 0) return false;
	return res <= C;
}

void solve(){
	scanf("%d %d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d %d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
		bfs(i, d[i]);

	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &a[i].v, &a[i].k, &a[i].p);
	}
	sort(a + 1, a + k + 1);
	scanf("%d", &qn);
	for (int i = 1; i <= qn; i++) {
		int v, K, C;
		scanf("%d %d %d", &v, &K, &C);
		int l = 0, r = n+n, res = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (ok(mid, v, K, C)) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		printf("%d\n", res);
	}

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