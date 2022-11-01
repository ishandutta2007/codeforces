#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct segTree {
	int n;
	vector<int> t;
	segTree(int n) : n(n), t(2 * n, INF) {}
	void upd(int v, int x) {
		v += n;
		t[v] = min(t[v], x);
		for(v >>= 1; v; v >>= 1) t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
	int get(int l, int r) {
		int ret = INF;
		for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if(l & 1) ret = min(ret, t[l]);
			if(!(r & 1)) ret = min(ret, t[r]);
		}
		return ret;
	}
};

int n;
string s;
vector<int> p;

bool glas(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
		|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int f(int x) {
	return (x >= 0 ? 3 * p[x] : 0) - 2 * x + 2 * n - 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	n = s.size();
	bool any = false;
	for(int i = 0; i < n; i++) any |= !glas(s[i]);
	if(!any) return cout << "No solution", 0;
	p.resize(n);
	for(int i = 0; i < n; i++) p[i] = (i ? p[i - 1] : 0) + glas(s[i]);
	segTree t(5 * n);
	int opt = 0;
	for(int i = 0; i < n; i++) {
		t.upd(f(i - 1), i);
		int x = t.get(f(i), 5 * n - 1);
		if(x == INF) continue;
		opt = max(opt, i - x + 1);
	}
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cur += glas(s[i]);
		if(i >= opt) cur -= glas(s[i - opt]);
		if(i + 1 >= opt) ans += (cur <= 2 * (opt - cur));
	}
	cout << opt << ' ' << ans;
}