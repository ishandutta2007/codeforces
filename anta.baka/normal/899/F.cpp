#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;

int t[4 * maxn];

void build(int v, int l, int r) {
	if(l == r) t[v] = 1;
	else {
		int m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

void upd(int v, int l, int r, int pos) {
	if(l == r) t[v] = 0;
	else {
		int m = (l + r) / 2;
		if(pos <= m) upd(v * 2 + 1, l, m, pos);
		else upd(v * 2 + 2, m + 1, r, pos);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

int get(int v, int l, int r, int x) {
	if(l == r) return l;
	int m = (l + r) / 2;
	if(t[v * 2 + 1] >= x) return get(v * 2 + 1, l, m, x);
	return get(v * 2 + 2, m + 1, r, x - t[v * 2 + 1]);
}

int n, q;
string s;
set<int> poses[62];

int code(char ch) {
	if(isdigit(ch)) return ch - '0';
	if('a' <= ch && ch <= 'z') return ch - 'a' + 10;
	return ch - 'A' + 36;
}

char recode(int x) {
	if(x < 10) return char('0' + x);
	if(x < 36) return char('a' + x - 10);
	return char('A' + x - 36);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	build(0, 0, n - 1);
	for(int i = 0; i < n; i++) poses[code(s[i])].insert(i);
	while(q--) {
		int l, r; char ch;
		cin >> l >> r >> ch;
		l = get(0, 0, n - 1, l);
		r = get(0, 0, n - 1, r);
		int c = code(ch);
		auto it = poses[c].lower_bound(l);
		while(it != poses[c].end() && (*it) <= r) {
			auto todel = it++;
			upd(0, 0, n - 1, *todel);
			poses[c].erase(todel);
		}
	}
	set<pair<int, int>> ret;
	for(int i = 0; i < 62; i++)
		for(int pos : poses[i])
			ret.insert({pos, i});
	for(pair<int, int> kek : ret)
		cout << recode(kek.second);
}