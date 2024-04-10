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
int n, q, a[N], mx[17][N], mn[17][N], Log[N];
pii f[34][17][N];

pii uni(pii u, pii v) {
	return mp(min(u.fi, v.fi), max(u.se, v.se));
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]), mx[0][i] = mn[0][i] = a[i];

	rep(j, 1, 16) {
		rep(i, 1, n) {
			if (i + (1 << j) - 1 > n) break;
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]); 
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]); 
		}
	}

	rep(j, 0, 16) {
		rep(l, 1, n) {
			int r = l + (1 << j) - 1;
			if (r > n) break;
			f[0][j][l] = mp(mn[j][l], mx[j][l]);
		}
	}

	rep(i, 2, n) Log[i] = Log[i >> 1] + 1;

	auto ask = [&](int k, int l, int r) {
		int o = Log[r - l + 1];
		return uni(f[k][o][l], f[k][o][r - (1 << o) + 1]);
	};

	rep(k, 1, 33) {
		rep(j, 0, 16) {
			rep(l, 1, n) {
				int r = l + (1 << j) - 1;
				if (r > n) break;
				pii o = f[k - 1][j][l];
				f[k][j][l] = ask(k - 1, o.fi, o.se);
			}
		}
	}

	while (q--) {
		int l, r;
		ll ans = 0;
		scanf("%d%d", &l, &r);

		if (l == 1 && r == n) {
			printf("%d\n", 0);
			continue;
		}

		per(k, 0, 33) {
			auto [nl, nr] = ask(k, l, r);

			if (nl != 1 || nr != n) {
				l = nl, r = nr;
				ans |= 1 << k;
			}
		}

		auto [nl, nr] = ask(0, l, r);
		if (nl == 1 && nr == n)
			printf("%lld\n", ans + 1);
		else
			printf("-1\n");
	}

	return 0;
}