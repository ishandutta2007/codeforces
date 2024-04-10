#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 10005;
int n;

pair <int, int> a[N];
set <pair <int, int> > ans;
void divide(int l, int r) {
	if (r - l == 1)
		return;
	int m = (l + r) / 2;
	divide(l, m);
	divide(m, r);
	for (int i = l; i < r; i++) {
		ans.insert({a[m].first, a[i].second});
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		ans.insert(a[i]);
	}
	sort(a, a + n);
	divide(0, n);
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}