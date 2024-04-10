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
const int N = 1005;
int n, a[N], mat[N];
bool vis[N * N];
vector<int> g[N * N];

bool dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;

	for (int v : g[u]) {
		if (mat[v] == -1 || dfs(mat[v]))
			return mat[v] = u, 1;
	}

	return 0;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d", &n);
	vector<int> num;

	rep(i, 1, n) {
		scanf("%d", &a[i]);
		rep(j, 1, n) num.pb(a[i] * j);
	}

	sort(all(num)), num.erase(unique(all(num)), num.end());

	rep(i, 1, n) {
		rep(j, 1, n) {
			g[lower_bound(all(num), a[i] * j) - num.begin()].pb(i);
		}
	}

	memset(mat, -1, sizeof mat);
	ll ans = 0;
	int cnt = 0;

	rep(i, 0, SZ(num) - 1) {
		if (cnt == n) break;

		if (dfs(i)) {
			ans += num[i];
			cnt++;
			memset(vis, 0, sizeof vis);
		}
	}

	printf("%lld\n", ans);
	return 0;
}