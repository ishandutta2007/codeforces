#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 222;
int n, p[N], q[N], fa[N];
bool use[N], hav[N][N];

int find(int x) {
	return fa[x] < 0 ? x : fa[x] = find(fa[x]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return 0;
	if (fa[u] > fa[v]) swap(u, v);
	fa[u] += fa[v], fa[v] = u;
	return 1;
}

void reset() {
	memset(fa + 1, -1, n << 2);
}

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &p[i]);
	memset(use + 1, 0, n << 2);
	use[q[1] = 1] = 1;

	rep(k, 2, n) {
		auto check = [&]() {
			rep(i, 1, n) hav[i - 1][i] = hav[i][i - 1] = 0;
			reset();
			rep(i, 1, n) merge(i, p[i]);

			rep(i, 1, k - 1) {
				int u = q[i], v = p[q[i + 1]];
				if (u <= v) {
					rep(i, u, v - 1) {
						if (hav[i][i + 1])
							return 0;
						hav[i][i + 1] = 1;
					}
				} else {
					rep(i, v, u - 1) {
						if (hav[i + 1][i])
							return 0;
						hav[i + 1][i] = 1;
					}
				}
			}

			rep(i, 1, n - 1) if (hav[i][i + 1] || hav[i + 1][i])
				if (!merge(i, i + 1)) return 0;

			vector<bool> on(n), bad(n), cur(n, 0);
			rep(i, 1, n) on[i] = find(i) == find(p[1]);
			reset();

			rep(i, 1, n) if (!use[i])
				merge(i, p[i]), cur[i] = cur[p[i]] = 1;

			rep(i, 1, n - 1) if (hav[i][i + 1] ^ hav[i + 1][i])
				merge(i, i + 1), cur[i] = cur[i + 1] = 1;

			rep(i, 1, n) bad[i] = on[i] && find(i) != find(p[1]);

			rep(i, 1, n - 1) if (!bad[i] && !bad[i + 1]) {
				merge(i, i + 1);
			}

			rep(i, 1, n) if (cur[i] && find(i) != find(p[1]))
				return 0;

			return 1;
		};

		rep(i, 1, n) if (!use[i]) {
			use[q[k] = i] = 1;
			if (check()) break;
			else use[i] = 0;
		}
	}

	rep(i, 1, n) printf("%d ", q[i]);
	printf("\n");
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();	
	return 0;
}