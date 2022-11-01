#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 300 * 1000 + 5;
int n, q, ans;


int a[N];
vector <int> vec[N];
vector <int> seg[N * 4];
vector <int> cand;
bool mark[N];

inline int cnt(int x, int l, int r) {
	return lower_bound(vec[x].begin(), vec[x].end(), r) - vec[x].begin() - (lower_bound(vec[x].begin(), vec[x].end(), l) - vec[x].begin());
}

void build(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		seg[id].push_back(a[s]);
		return;
	}
	for (int i = s; i < e; i++) {
		if (cnt(a[i], s, e) * 5 > e - s) {
			bool b = true;
			for (auto x : seg[id]) {
				if (x == a[i]) {
					b = false;
				}
			}
			if (b) {
				seg[id].push_back(a[i]);
			}
		}
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
}

void get(int l, int r, int k, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		for (auto x : seg[id]) {
			if (!mark[x]) {
				mark[x] = true;
				cand.push_back(x);
				if (cnt(x, l, r) * k > r - l) {
					ans = min(ans, x);
				}				
			}

		}
		return;
	}
	int md = (s + e) / 2;
	get(l, r, k, id * 2, s, md);
	get(l, r, k, id * 2 + 1, md, e);
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vec[a[i]].push_back(i);
	}
	build();
	for (int i = 0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		ans = N;
		get(l, r, k);
		if (ans == N) {
			cout << -1;
		}
		else {
			cout << ans;
		}
		cout << '\n';
		for (auto x : cand) {
			mark[x] = false;
		}
		cand.clear();
	}
	return 0;
}