// Problem: B. Berkomnadzor
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 2e5;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, ch[N * 32 + 5][2], s[2][N * 32 + 5], top;
bool vis[N * 32 + 5];
struct pii {int x, y;};
vector<pii> ans;

void ins(int n, int m, int t) {
	// cout << n << ' ' << m << ' ' << t << endl;
	int now = 0;
	++s[t][0];
	per(i, 31, 31 - m + 1) {
		int v = (n >> i) & 1;
		if(!ch[now][v]) ch[now][v] = ++top;
		now = ch[now][v];
		++s[t][now];
	}
	vis[now] = 1;
}
void dfs(int n, int val, int dep) {
	// cout << ch[n][0] << ' ' << ch[n][1] << endl;
	if(!s[0][n]) return;
	if(s[0][n] && !s[1][n]) {
		ans.PB((pii) {val, 31 - dep});
		return;
	}
	if(dep < 0 || vis[n]) {
		puts("-1");
		exit(0);
	}
	if(ch[n][0]) dfs(ch[n][0], val, dep - 1);
	if(ch[n][1]) dfs(ch[n][1], val | (1ll << dep), dep - 1);
}
void print(int n, int m) {
	assert(!(n & ((1ll << (32 - m)) - 1)));
	int x = (n >> 24), y = (n >> 16) & 255, z = (n >> 8) & 255, w = n & 255;
	if(m != 32) printf("%lld.%lld.%lld.%lld/%lld\n", x, y, z, w, m);
	else printf("%lld.%lld.%lld.%lld\n", x, y, z, w);
}

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	int x, y, z;
	char o;
	rep(i, 1, a) {
		while((o = getchar()) != '-' && o != '+');
		z = (o == '+');
		x = read();
		x = (x << 8) | read();
		x = (x << 8) | read();
		y = 0;
		while((o = getchar()) >= '0' && o <= '9') y = y * 10 + o - '0';
		x = (x << 8) | y;
		y = 32;
		if(o == '/') y = read();
		ins(x, y, z);
	}
	dfs(0, 0, 31);
	printf("%lld\n", siz(ans));
	rep(i, 0, siz(ans) - 1) print(ans[i].x, ans[i].y);
	return 0;
}