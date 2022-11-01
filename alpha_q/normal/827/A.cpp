#include <bits/stdc++.h>

using namespace std;

struct range {
	int l, r, id;
	range () {}
	range (int _l, int _r, int _id) {
		l = _l, r = _r, id = _id;
	}
	bool operator < (const range &other) const {
		return l == other.l ? r > other.r : l < other.l;
	} 
};

const int N = 100010;
const int M = 2000010;

char s[M];
string t[N];
int n, k[N], ptr;
range xyz[M];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	int ends = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> k[i];
		int sz = t[i].size();
		for (int j = 0; j < k[i]; ++j) {
			int x;
			cin >> x;
			xyz[++ptr] = range(x, x + sz - 1, i);
			ends = max(ends, x + sz - 1);
		}
	}
	for (int i = 1; i <= ends; ++i) {
		s[i] = '?';
	}
	sort(xyz + 1, xyz + ptr + 1);
	int last = 0;
	for (int i = 1; i <= ptr; ++i) {
		int l = xyz[i].l, r = xyz[i].r, id = xyz[i].id;
		if (r <= last) continue;
		int at = l, pos = 0;
		if (l <= last) at = last + 1, pos = last - l + 1;
		while (at <= r) {
			s[at] = t[id][pos];
			++at, ++pos;
		}
		last = max(last, r);
	}
	for (int i = 1; i <= ends; ++i) {
		if (s[i] == '?') s[i] = 'a';
		cout << s[i];
	}
	cout << '\n';
	return 0;
}