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
const int N = 100015;
bool vis[N];
int n, a[N];

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	vector<vector<int>> op;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	vector<int> vec;

	rep(_, 0, 1) {
		int w = -1, g = -1, c = 0;
		rep(i, 1, n) if (!vis[i]) {
			w = i, g = a[i];
			vis[i] = 1;
			break;
		}

		if (w == -1) continue;

		vector<int> p;
		int x = g;

		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				p.pb(i);

				while (x % i == 0) {
					x /= i;
				}
			}
		}

		if (x > 1) p.pb(x);
		
		for (int o : p) {
			int mn = inf, pos = -1;

			rep(i, 1, n) if (!vis[i]) {
				int cnt = 0, u = a[i];

				while (u % o == 0) {
					u /= o;
					cnt++;
				}

				if (cnt < mn) {
					mn = cnt;
					pos = i;
				}
			}

			int cnt = 0, u = g;

			while (u % o == 0) {
				u /= o;
				cnt++;
			}

			if (pos == -1 || mn >= cnt) continue;
			vis[pos] = 1;
			c++;
			g = __gcd(g, a[pos]);
		}

		if (c == 7) vis[w] = 0;
	}

	rep(i, 1, n) if (vis[i]) vec.pb(i);
	int m = SZ(vec);

	rep(s, 1, (1 << m) - 1) {
		int u = __builtin_popcount(s);
		int v = (u & 1 ? -1 : 1) * (u - 2);
		vector<int> cur(1, v > 0 ? 0 : 1);

		rep(i, 0, m - 1) if (s >> i & 1) {
			cur.pb(vec[i]);
		}

		cur.insert(cur.begin() + 1, SZ(cur) - 1);

		rep(_, 1, abs(v)) {
			op.pb(cur);
		}
	}

	printf("%d\n", SZ(op));

	for (auto cur : op) {
		for (int x : cur) printf("%d ", x);
		printf("\n");
	}

	return 0;
}