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

const int N = 200015;
int n, p[N], q[N];
vector<int> a[N], b[N];

void FK(vector<int> vec) {
	int o = SZ(vec);

	rep(i, 0, o - 1) q[vec[(i + 1) % o]] = p[vec[i]];
}

void solve() {
	scanf("%d", &n);

	rep(i, 0, n) a[i].clear(), b[i].clear();

	rep(i, 1, n) {
		scanf("%d", &p[i]);
		a[p[i]].pb(i);
	}

	rep(i, 1, n) {
		rep(j, 0, SZ(a[i]) - 1) b[j].pb(a[i][j]);
	}

	rep(j, 0, n - 1) FK(b[j]);

	rep(i, 1, n) printf("%d%c", q[i], " \n"[i == n]);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T; T--) solve();

	return 0;
}