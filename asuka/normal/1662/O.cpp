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

bool Ans, C[25][366], S[25][366], vis[25][366];
int n;

void dfs(int x, int y) {
	vis[x][y] = 1;

	// x + 1
	if (!C[x][y]) {
		if (x == 20) Ans = 1;
		else if (!vis[x + 1][y]) dfs(x + 1, y);
	}

	// x - 1

	if (x > 1 && !C[x - 1][y]) {
		if (!vis[x - 1][y]) dfs(x - 1, y);
	}

	// y + 1

	if (!S[x][(y + 1) % 360]) {
		if (!vis[x][(y + 1) % 360]) dfs(x, (y + 1) % 360);
	}

	// y - 1

	if (!S[x][y]) {
		if (!vis[x][(y - 1 + 360) % 360]) dfs(x, (y - 1 + 360) % 360);
	}
}

void solve() {
	memset(C, 0, sizeof C);
	memset(S, 0, sizeof S);
	memset(vis, 0, sizeof vis);
	Ans = 0;
	cin >> n;

	rep(_, 1, n) {
		char ch; int x, y, z;
		cin >> ch >> x >> y >> z;

		if (ch == 'C') {
			for (int i = y; i != z; i = (i + 1) % 360) {
				C[x][i] = 1;
			}

		} else {
			rep(i, x + 1, y) S[i][z] = 1;
		}
	}

	dfs(1, 0);

	puts(Ans ? "YES" : "NO");
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;

	for (cin >> T; T; T--) solve();

	return 0;
}