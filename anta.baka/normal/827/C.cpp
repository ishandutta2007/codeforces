#include <bits/stdc++.h>

using namespace std;

struct fen {
	int n; vector<int> t;
	fen(int _n) { n = _n; t.resize(n, 0); }
	void upd(int v, int x) { for(int i = v; i < n; i |= i + 1) t[i] += x; }
	int pref(int v) { int res = 0; for(int i = v; i >= 0; i = (i & (i + 1)) - 1) res += t[i]; return res; }
	int seg(int l, int r) { return pref(r) - pref(l - 1); }
};

int n, q;
string s;

int f(char c) { return c == 'A' ? 0 : c == 'T' ? 1 : c == 'G' ? 2 : 3; }

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s >> q; n = s.size();
	vector<vector<vector<fen>>> t(4, vector<vector<fen>>(10, vector<fen>(10, fen(n))));
	for(int i = 0; i < n; i++) for(int j = 0; j < 10; j++) t[f(s[i])][j][i % (j + 1)].upd(i, 1);
	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int x; char c; cin >> x >> c; --x;
			for(int i = 0; i < 10; i++) t[f(s[x])][i][x % (i + 1)].upd(x, -1);
			for(int i = 0; i < 10; i++) t[f(c)][i][x % (i + 1)].upd(x, 1);
			s[x] = c;
		} else {
			int l, r; string e; cin >> l >> r >> e; --l; --r; int len = e.size(), ans = 0;
			for(int i = 0; i < len && l + i <= r; i++) {
				ans += t[f(e[i])][len - 1][(l + i) % len].seg(l + i, n - 1) - (r < n - 1 ? t[f(e[i])][len - 1][(l + i) % len].seg(r + 1, n - 1) : 0);
				//int rr = i + l + ((r - l - i + len) / len) * len;
				//if(rr < n) ans -= t[f(e[i])][len - 1][rr % len].seg(rr, n - 1);
			}
			cout << ans << '\n';
		}
	}
}