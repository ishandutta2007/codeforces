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
int n, L[2015];
bool G[2015][2015];

void add(int u, int v) {
	printf("%d %d\n", u, v);
}

void gao(int l, int r) {
	if (l == r) return;
	vector<int> vec, rem;

	for (int i = r - 1; i >= l; i = L[i] - 1)
		gao(L[i], i), vec.pb(i);

	int las = -1;

	rep(i, 0, SZ(vec) - 1) {
		int u = vec[i];

		per(j, L[u], u) {
			if (G[j][r]) {
				add(j, r);
				rep(k, las + 1, i - 1)
					add(vec[k], k == i - 1 ? r : j);
				las = i;
				break;
			}
		}
	}
}

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) L[i] = inf;

	rep(i, 1, n) {
		int x;
		rep(j, i, n) {
			scanf("%1d", &x);
			G[i][j] = x;
			if (x) L[j] = min(L[j], i);
		}
	}

	gao(1, n);
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