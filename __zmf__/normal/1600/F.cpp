#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define siz(a) ((int) a.size())
#define PB push_back
#define LL long long
const int N = 100;
const int M = 1e5;
const int mod = 998244353;
const int inf = 1e9;

int read() {
	int x = 0, y = 0;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; y |= (ch == '-'), ch = getchar());
	for(; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar());
	return x * (y ? -1 : 1);
}

int a, b;
bool s[N + 5][N + 5];
vector<int> st, ans[N + 5];

void dfs0(int n, vector<int> p, vector<int> o) {
	if(siz(o) > siz(ans[n])) ans[n] = o;
	vector<int> q;
	rep(i, 0, siz(p) - 1) {
		int m = p[i];
		if(siz(o) + siz(ans[m]) < siz(ans[n])) continue;
		q.clear();
		rep(j, i + 1, siz(p) - 1) if(!s[m][p[j]]) q.PB(p[j]);
		if(siz(o) + 1 + siz(q) < siz(ans[n])) continue;
		o.PB(m);
		dfs0(n, q, o);
		o.pop_back();
	}
}

void dfs1(int n, vector<int> p, vector<int> o) {
	if(siz(o) > siz(ans[n])) ans[n] = o;
	vector<int> q;
	rep(i, 0, siz(p) - 1) {
		int m = p[i];
		if(siz(o) + siz(ans[m]) < siz(ans[n])) continue;
		q.clear();
		rep(j, i + 1, siz(p) - 1) if(s[m][p[j]]) q.PB(p[j]);
		if(siz(o) + 1 + siz(q) < siz(ans[n])) continue;
		o.PB(m);
		dfs1(n, q, o);
		o.pop_back();
	}
}

signed main() {
//	freopen("in.txt", "r", stdin);
	a = read();
	b = read();
	int x, y;
	rep(i, 1, b) {
		x = read();
		y = read();
		if(x <= 63 && y <= 63)s[x][y] = s[y][x] = 1;
	}
	a = min(43, a);
	per(i, a, 1) {
		st.clear();
		rep(j, i + 1, a) if(!s[i][j]) st.PB(j);
		dfs0(i, st, {i});
	}
	int res = 0;
	rep(i, 1, a) if(siz(ans[i]) > siz(ans[res])) res = i;
	if(siz(ans[res]) >= 5) {
		rep(i, 0, 4) printf("%d ", ans[res][i]);
		return 0;
	}
	rep(i, 1, a) ans[i].clear();
	per(i, a, 1) {
		st.clear();
		rep(j, i + 1, a) if(s[i][j]) st.PB(j);
		dfs1(i, st, {i});
	}
	res = 0;
	rep(i, 1, a) if(siz(ans[i]) > siz(ans[res])) res = i;
	if(siz(ans[res]) >= 5) {
		rep(i, 0, 4) printf("%d ", ans[res][i]);
		return 0;
	}
	puts("-1");
	return 0;
}