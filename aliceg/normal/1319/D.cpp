#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <random>

#define endl '\n'
#define rn(n) int n; cin >> n
#define pb push_back
#define mp make_pair
#define fi(n) for(int i = 0; i < n; ++i)
#define fir(l, r) for(int i = l; i <= r; ++i)
#define fj(n) for(int j = 0; j < n; ++j)
#define fjr(l, r) for(int j = l; j <= r; ++j)
#define fv(i, n) for(int i = 0; i < n; ++i)
#define fvr(i, l, r) for(int i = l; i <= r; ++i)
//#define int ll

#pragma warning (disable : 4996)
//#pragma optimize (linker, "STACK:16777216")

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void bfs(int s, int n, vvi& a, vi& d) {
	queue<int> q;
	vc used(n);
	used[s] = 1;
	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : a[v]) {
			if (!used[u]) {
				d[u] = d[v] + 1;
				q.push(u);
				used[u] = 1;
			}
		}
	}
	return;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	rn(n); rn(m);
	vvi a(n), b(n);
	fi(m) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[v].pb(u);
		b[u].pb(v);
	}
	rn(k);
	vi p(k);
	fi(k) {
		cin >> p[i];
		--p[i];
	}
	vi d(n, INF);
	bfs(p.back(), n, a, d);
	int minn = 0, maxx = 0;
	fi(k - 1) {
		if (d[p[i]] - 1 != d[p[i + 1]]) {
			++minn;
			++maxx;
		}
		else {
			int cnt = 0;
			for (int u : b[p[i]]) {
				if (d[u] + 1 == d[p[i]])
					++cnt;
				if (cnt > 1)
					break;
			}
			if (cnt > 1)
				++maxx;
		}
	}
	cout << minn << ' ' << maxx;

	return 0;
}