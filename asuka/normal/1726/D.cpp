#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
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
const int N = 200015;
int n, m, fa[N], buc[N];
bool vis[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve() {
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int>> vec;
	vec.reserve(m);
	rep(i, 1, max(n, m)) fa[i] = i, vis[i] = 0, buc[i] = 0;

	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		vec.eb(u, v, i);
	}

	int cnt = 0;

	for (auto [u, v, ___] : vec) {
		int fu = find(u), fv = find(v);

		if (fu == fv) {
			vis[___] = 1;
			cnt++;
			buc[u]++;
			buc[v]++;
		} else fa[fu] = fv;

		if (m - cnt == n - 1)
			break;

		if (cnt == 2) {
			if (*max_element(buc + 1, buc + n + 1) == 2) {
				int x = -1, y = -1, id = -1;
				rep(i, 1, n) if (buc[i] == 1) (x == -1 ? x : y) = i;

				for (auto [p, q, j] : vec) {
					if (p == x && q == y) {
						id = j;
					}
				}	

				if (~id) {
					vec.erase(find(all(vec), make_tuple(x, y, id)));
					vec.insert(vec.begin(), make_tuple(x, y, id));
				}
			}

			break;
		}
	}

	rep(i, 1, n) fa[i] = i;

	for (auto [u, v, ___] : vec) {
		if (vis[___]) continue;
		int fu = find(u), fv = find(v);

		if (fu == fv) {
			vis[___] = 1;
		} else fa[fu] = fv;
	}

	rep(i, 1, m) printf("%d", vis[i]);
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