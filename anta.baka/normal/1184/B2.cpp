#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int inf = (int)1e9 + 100;

int n, m;
int d[100][100];
int s, b, k, h;

struct ship {
	int x, a, f;
} ss[1000];

struct base {
	int x, d;
} bb[1000];

vi g[1000];
int par[1000];
bool was[1000];

bool kuhn(int v) {
	if (was[v]) return false;
	was[v] = true;
	for (int to : g[v]) {
		if (par[to] == -1 || kuhn(par[to])) {
			par[to] = v;
			return true;
		}
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(i != j) d[i][j] = inf;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; d[u][v] = d[v][u] = 1;
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	cin >> s >> b >> k >> h;
	for (int i = 0; i < s; i++) cin >> ss[i].x >> ss[i].a >> ss[i].f, --ss[i].x;
	for (int i = 0; i < b; i++) cin >> bb[i].x >> bb[i].d, --bb[i].x;
	for (int i = 0; i < s; i++) for (int j = 0; j < b; j++) if (ss[i].a >= bb[j].d && ss[i].f >= d[ss[i].x][bb[j].x]) g[i].pb(j);
	int mat = 0;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < s; i++) {
		memset(was, false, sizeof(was));
		mat += kuhn(i);
	}
	ll ans = (ll)1e18;
	for (int fb = 0; fb <= s; fb++) {
		ans = min(ans, 1LL * fb * h + 1LL * k * (mat - max(0, fb - (s - mat))));
	}
	cout << ans;
}