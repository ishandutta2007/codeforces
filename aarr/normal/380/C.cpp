#include <iostream>
using namespace std;


const int N = 1000 * 1000 + 5;
int n;

pair <int, pair <int, int> > seg[N  * 4];
string s;

void build(int id = 1, int L = 0, int R = s.size()) {
	if (R - L == 1) {
		if (s[L] == '(') {
			seg[id] = {0, {1, 0}};
		}
		else {
			seg[id] = {0, {0, 1}};
		}
		return;
	}
	int md = (L + R) / 2;
	build(id * 2, L, md);
	build(id * 2 + 1, md, R);
	seg[id].second.first = seg[id * 2].second.first + seg[id * 2 + 1].second.first;
	seg[id].second.second = seg[id * 2].second.second + seg[id * 2 + 1].second.second;
	seg[id].first = seg[id * 2].first + seg[id * 2 + 1].first;
	seg[id].first += min(seg[id * 2].second.first - seg[id * 2].first, seg[id * 2 + 1].second.second - seg[id * 2 + 1].first);
}
pair <int, pair <int, int> > get(int l, int r, int id = 1, int L = 0, int R = s.size()) {
	if (r <= L || R <= l) {
		return {0, {0, 0}};
	}
	if (l <= L && R <= r) {
		return seg[id];
	}
	int md = (L + R) / 2;
	pair <int, pair <int, int> > p1 = get(l, r, id * 2, L, md);
	pair <int, pair <int, int> > p2 = get(l, r, id * 2 + 1, md, R);
	int ans = 0;
	ans = p1.first + p2.first;
	ans += min(p1.second.first - p1.first, p2.second.second - p2.first);
	return {ans, {p1.second.first + p2.second.first, p1.second.second + p2.second.second}};
}
int main() {
	cin >> s;
//	int n = s.size();
	build();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << 2 * get(l, r).first << endl;
	}
	return 0;
}