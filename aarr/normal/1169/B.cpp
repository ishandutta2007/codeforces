#include <iostream>
using namespace std;

pair<int, int> a[300005];
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
	}
	int x = a[0].first, y = a[0].second, p, q;
	bool b = true;
	for (int i = 1; i < m; i++) {
		if (a[i].first != x && a[i].second != x && a[i].first != y && a[i].second != y) {
			b = false;
			p = a[i].first;
			q = a[i].second;
		}
	}
	if (b)
		cout << "YES";
	else {
		//cout << x << " " << y << " " << p << " " << q << endl;
		bool c = true, d = true, e = true, f = true;
		for (int i = 1; i < m; i++) {
			if (a[i].first != x && a[i].second != x && a[i].first != p && a[i].second != p) {
				c = false;
			}
		}
		for (int i = 1; i < m; i++) {
			if (a[i].first != x && a[i].second != x && a[i].first != q && a[i].second != q) {
				d = false;
			}
		}
		for (int i = 1; i < m; i++) {
			if (a[i].first != y && a[i].second != y && a[i].first != p && a[i].second != p) {
				e = false;
			}
		}
		for (int i = 1; i < m; i++) {
			if (a[i].first != y && a[i].second != y && a[i].first != q && a[i].second != q) {
				f = false;
			}
		}
		if (c || d || e || f)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}