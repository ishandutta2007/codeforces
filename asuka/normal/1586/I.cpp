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
const int N = 2015;
int n;
char s[N][N];
bool v[N][N], c[N][N];

void dfs(int i, int j) {
	auto push = [&](int ni, int nj, int o) {
		if (0 <= min(ni, nj) && max(ni, nj) < n && !v[ni][nj]) {
			c[ni][nj] = c[i][j] ^ o;
			dfs(ni, nj);
		}
	};

	v[i][j] = 1;

	if ((i + j) & 1) {
		push(i + 1, j + 1, 1);
		push(i - 1, j - 1, 1);
	} else {
		push(i + 1, j - 1, 1);
		push(i - 1, j + 1, 1);
	}

	if (!i || i == n - 1)
		push(i, j ^ 1, 0);
	
	if (!j || j == n - 1)
		push(i ^ 1, j, 0);
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d", &n);
	rep(i, 0, n - 1) scanf("%s", s[i]);
	if (n & 1) return puts("NONE"), 0;
	
	rep(i, 0, n - 1) rep(j, 0, n - 1) {
		if (!v[i][j] && s[i][j] != '.') {
			c[i][j] = s[i][j] == 'S';
			dfs(i, j);
		}
	}

	rep(i, 0, n - 1) rep(j, 0, n - 1) {
		if (s[i][j] != '.' && c[i][j] != (s[i][j] == 'S'))
			return puts("NONE"), 0;
	}

	rep(i, 0, n - 1) rep(j, 0, n - 1) {
		if (!v[i][j])
			return puts("MULTIPLE"), 0;
	}

	puts("UNIQUE");

	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) printf("%c", "GS"[c[i][j]]);
		printf("\n");
	}
	return 0;
}