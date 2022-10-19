#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 1015;

char s[N];
int cnt[3][33];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int L = 1000;

	rep(_, 0, 2) {
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		L = min(L, n);

		rep(i, 1, n) cnt[_][s[i] - 'A']++;
	}

	int l = 0;
	vector<int> v[3], vv[3];

	rep(c, 0, 25) {
		int x = 0, y = 0, z = 0;

		rep(cx, 0, min(cnt[0][c], cnt[1][c])) rep(cy, 0, min(cnt[1][c] - cx, cnt[2][c])) {
			int cz = min({cnt[0][c] - cx, cnt[2][c] - cy, L - l - cx - cy});

			if (cz < 0) continue;

			if (cx + cy + cz > x + y + z) {
				tie(x, y, z) = make_tuple(cx, cy, cz);
			}
		}

		l += x + y + z;
		v[1].insert(v[1].end(), z, c); cnt[1][c] -= x + y;
		v[2].insert(v[2].end(), x, c); cnt[2][c] -= y + z;
		v[0].insert(v[0].end(), y, c); cnt[0][c] -= z + x;

	}

	rep(c, 0, 25) rep(_, 0, 2) vv[_].insert(vv[_].end(), cnt[_][c], c);

	vector<pii> ans;

	auto Push = [&](vector<int> &u, vector<int> &v) {
		if (v.empty()) v.pb(0);

		ans.emplace_back(u.back(), v.back());
		u.pop_back(); v.pop_back();
	};

	rep(_, 0, 2) {
		while (!v[_].empty())
			Push(v[_], vv[_]);
	}

	while (!vv[0].empty() || !vv[1].empty() || !vv[2].empty()) {
		int ord[3] = {0, 1, 2};
		sort(ord, ord + 3, [&](int u, int v) {return SZ(vv[u]) > SZ(vv[v]);});
		Push(vv[ord[0]], vv[ord[1]]);
	}

	printf("%d\n", SZ(ans));

	for (auto [x, y] : ans) printf("%c%c\n", x + 'A', y + 'A');

	return 0;
}