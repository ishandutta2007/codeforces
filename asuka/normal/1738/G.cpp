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
const int N = 1015;
int n, k;
char s[N][N];
bool ans[N][N];
vector<int> z[N];

int w(int x, int y) {
	return min(x, y) + min(n - x, n - y);
}

bool vld(int x, int y) {
	return w(x, y) >= k - 1;
}

void solve() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%s", s[i] + 1);

	rep(j, 1, n) {
		z[j].clear();
		per(i, 1, n) if (vld(i, j) && (s[i][j] == '0' || w(i, j) == k - 1))
			z[j].pb(i);
	}

	rep(i, 1, n) rep(j, 1, n) ans[i][j] = 0;

	for (int p = n - k + 2, q = 1; p <= n; p++, q++) {
		int x = p, y = q;

		while (vld(x, y)) {
			ans[x][y] = 1;
			while (!z[y].empty() && ans[z[y].back()][y])
				z[y].pop_back();
			if (!z[y].empty() && z[y].back() < x)
				x--;
			else y++;
		}
	}

	bool fl = 0;

	rep(i, 1, n) rep(j, 1, n) 
		if (vld(i, j) && s[i][j] == '0' && !ans[i][j])
			fl = 1;

	if (fl) puts("NO");
	else {
		puts("YES");
		rep(i, 1, n) {
			rep(j, 1, n)
				printf("%d", !vld(i, j) || ans[i][j]);
			printf("\n");
		}
	}
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