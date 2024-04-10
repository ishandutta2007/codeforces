#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 200 * 1000 + 5;

int seg[4 * N];
pair <int, int> a[N];
vector <int> hasl[N];
vector <int> hasr[N];
set <pair < pair <int, int>, int> > s;
vector <int> ans;
void update(int l, int r, int x, int id = 1, int L = 0, int R = N) {
	if (l <= L && R <= r) {
		seg[id] += x;
		return;
	}
	if (R <= l || r <= L) {
		return;
	}
	int md = (L + R) / 2;
	update(l, r, x, id * 2, L, md);
	update(l, r, x, id * 2 + 1, md, R);
}
int get(int i, int id = 1, int L = 0, int R = N) {
	if (i < L || R <= i)
		return 0;
	if (R - L == 1)
		return seg[id];
	int md = (L + R) / 2;
	int ans = seg[id];
	ans += get(i, id * 2, L, md);
	ans += get(i, id * 2 + 1, md, R);
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].second >> a[i].first;
		hasl[a[i].second].push_back(i);
		hasr[a[i].first].push_back(i);
		update(a[i].second, a[i].first + 1, 1);
	}
	//for (int i = 0; i <= 20; i++) {
	//	cout << i << " " << get(i) << endl;
	//}
	for (int i = 1; i < N; i++) {
		for (auto x : hasl[i]) {
			s.insert({{-a[x].first, a[x].second}, x});
		}
		while (get(i) > k) {
			pair <pair <int, int>, int> p = *s.begin();
			s.erase(s.begin());
			ans.push_back(p.second);
			update(p.first.second, -p.first.first + 1, -1);
		}
		for (auto x : hasr[i]) {
			s.erase({{-a[x].first, a[x].second}, x});
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}