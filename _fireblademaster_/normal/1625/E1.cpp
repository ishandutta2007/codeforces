#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 300005;
int n, q;
char s[N], str[N];
int match[N];
vector<int> G[N];
vector<ll> H[N];
ll dp[N];
int vis[N];
int id[N], fa[N];
int sta[N], top = 0;

ll func(int x) {
	return 1LL * x * (x + 1) / 2;
}

void dfs(int x) {
	dp[x] = func(sz(G[x]));
	for (int i = 0; i < sz(G[x]); ++i) {
		int to = G[x][i];
		id[to] = i;
		dfs(to);
		H[x].push_back(dp[to]);
		dp[x] += dp[to];
	}
	for (int i = 1; i < sz(H[x]); ++i) {
		H[x][i] += H[x][i - 1];
	}
}

void init() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	top = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') {
			sta[++top] = i; 
		} else {
			if (top) {
				vis[sta[top]] = vis[i] = 1;
				--top;
			}
		}
	}
	top = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) continue;
		if (s[i] == '(') {
			fa[i] = sta[top];
			G[fa[i]].push_back(i);
			sta[++top] = i;
		} else {
			match[sta[top]] = i;
			match[i] = sta[top--];
		}
	}
	dfs(0);
}

ll calc(int l, int r) {
	if (match[l] == r) {
		return dp[l] + 1;
	}
	int ql = id[l], qr = id[match[r]], x = fa[l];
	ll ans = H[x][qr];
	if (ql) ans -= H[x][ql - 1];
	ans += func(qr - ql + 1);
	return ans;
}

void solve() {
	int t, l, r;
	while (q--) {
		scanf("%d%d%d", &t, &l, &r);
		printf("%lld\n", calc(l, r));
	}
}

int main() {
	int t = 1;
#ifdef CASES_WITH_T
	scanf("%d", &t); 
#endif
	while (t--) {
		init();
		solve();
	}
	return 0;
}