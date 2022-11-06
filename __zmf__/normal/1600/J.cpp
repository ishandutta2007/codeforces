#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define siz(a) ((int) a.size())
#define PB push_back
#define LL long long
const int N = 1000;
const int M = 1e5;
const int mod = 1e9 + 7;
const int inf = 1e9;

int read() {
	int x = 0, y = 0;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; y |= (ch == '-'), ch = getchar());
	for(; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
	return x * (y ? -1 : 1);
}

int a, b, s[N + 5][N + 5], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, val;
bool vis[N + 5][N + 5];
vector<int> ans;

void dfs(int n, int m) {
	vis[n][m] = 1;
	++val;
	rep(i, 0, 3) if(!(s[n][m] & (1 << i)) && !vis[n + dx[i]][m + dy[i]]) dfs(n + dx[i], m + dy[i]);
}

signed main() {
//	freopen("in.txt", "r", stdin);
	a = read();
	b = read();
	rep(i, 1, a) rep(j, 1, b) s[i][j] = read();
	rep(i, 1, a) rep(j, 1, b) if(!vis[i][j]) {
		dfs(i, j);
		ans.PB(val);
		val = 0;
	}
	sort(ans.begin(), ans.end(), greater<int>());
	rep(i, 0, siz(ans) - 1) printf("%d ", ans[i]);
	return 0;
}