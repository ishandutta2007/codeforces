#include <bits/stdc++.h>
using namespace std;

#define PB push_back
// #define int long long
#define ll long long
#define vi vector<int>
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 2e5;
int a, b, c, pre[N + 5], vis[N + 5];
vi st[N + 5];

void ANS(int n, int o) {
	if(o && n == c) return cout << o + 1 << '\n' << c << ' ', void();
	ANS(pre[n], o + 1);
	cout << n << "\n "[o != 0];
}
void dfs(int n, int fa) {
	vis[n] = fa;
	for(int v : st[n]) {
		if(vis[v] == fa || v == c) continue;
		if(pre[v]) {
			cout << "Possible\n";
			ANS(v, 0);
			pre[v] = n;
			ANS(v, 0);
			exit(0);
		}
		pre[v] = n;
		if(v != c) dfs(v, fa);
	}
}

signed main() {
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> c;
	int x, y;
	rep(i, 1, b) {
		cin >> x >> y;
		st[x].PB(y);
	}
	for(int x : st[c]) {
		if(pre[x] && pre[x] != c) {
			cout << "Possible\n";
			ANS(x, 0);
			cout << "2\n" << c << ' ' << x << '\n';
			return 0;
		}
		pre[x] = c;
		dfs(x, x);
	}
	cout << "Impossible";
	return 0;
}