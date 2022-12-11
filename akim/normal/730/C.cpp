#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll int
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;
const int N = int(3e5), inf = int(1e9) + 7;

ll n, m, x, y, c[N], k[N], p[N];
vector<ll> a[N], smas[N];
vector<pair<ll, ll> > gg[N];
ll s, R, A;
pair<ll, int> d[N], b[N];
int q[N], cc, cnt;
priority_queue<pair<ll, ll> > st;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		a[x].pb(y);
		a[y].pb(x);
	}

	int w;

	cin >> w;
	for (int i = 1; i <= w; i++) {
		scanf("%d%d%d", &cc, &k[i], &p[i]);
		gg[cc].pb(mp(k[i], p[i]));
	}

	int qq;
	scanf("%d", &qq);
	for (int T = 1; T <= qq; T++) {
		scanf("%d%d%d", &s, &R, &A);
		for (int i = 1; i <= n; i++)
			d[i].f = -1, d[i].s = i;
		d[s].f = 0;
		q[0] = s;
		int l = 0, r = 0;
		while (l <= r) {
			int v = q[l++];
			for (int i = 0; i < a[v].size(); i++) {
				int to = a[v][i];
				if (d[to].f == -1) {
					d[to].f = d[v].f + 1;
					q[++r] = to;
				}
			}
		}

		for (int i = 0; i <= n + 1; i++) {
			smas[i].clear();
		}

		for (int i = 1; i <= n; i++)
			smas[d[i].f + 1].pb(d[i].s);

		cnt = 0;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j < smas[i].size(); j++) {
				int vv = smas[i][j];
				b[++cnt] = mp(i - 1, vv);

			}

		}

		for (int i = 1; i <= n; i++)
			d[i] = b[i];

	 	long long Res = 0, ALL = 0, ARes = inf;
		while (!st.empty())
			st.pop();
		for (int i = 1; i <= n; i++) {
			if (d[i].f == -1)
				continue;


	 	 	for (int j = 0; j < gg[d[i].s].size(); j++) {
				int kk = gg[d[i].s][j].f;
				int pp = gg[d[i].s][j].s;

				if (ALL < R) {
					int x = min(kk*1ll, R - ALL);
					kk -= x;
					ALL += x;
					Res += x * 1ll * pp;
					st.push(mp(pp, x));
				}

				int fa = 0, fb = 0;

				while (fa < kk && !st.empty()) {
					pair<int, int> ff = st.top();
					if (ff.f < pp)
						break;
					st.pop();
					int x = min(kk - fa, ff.s);

					fa += x;
					ff.s -= x;

					Res -= ff.f *1ll * x;

					if (ff.s > 0) {
						st.push(ff);
						break;
					}
				}
				Res += fa *1ll* pp;
				st.push(mp(pp, fa));
				if (ALL == R && Res <= A) {
					ARes = min(ARes, 1ll*d[i].f);
				}

			}


	 	}


		if (ARes != inf) {
			printf("%d\n", ARes);
		} else {
			printf("-1\n");
		}

	}

	return 0;
}