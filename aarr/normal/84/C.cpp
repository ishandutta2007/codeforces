#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000 * 1000 * 1000 + 7;

pair <pair <int, int>, int> a[10005];
pair <int, int> b[200005];
int ans[10005];
int main() {
	int n, m, p = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.first;
		cin >> a[i].first.second;
		a[i].second = i + 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i].first;
		cin >> b[i].second;
	}
	sort(a, a + n);
	for (int i = 1; i <= n; i++) {
		ans[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		pair <pair <int, int>, int> t = {{b[i].first, 0}, 0};
		int j = lower_bound(a, a + n, t) - a;
		//cout << i << " " << j << " " << b[i].first << endl;
		if (j >= n)
			j --;
		if ((a[j].first.first - b[i].first) * (a[j].first.first - b[i].first) + b[i].second * b[i].second <= a[j].first.second * a[j].first.second && ans[a[j].second] == -1) {
			ans[a[j].second] = i + 1;
			p ++;
			//cout << 735 << " " << i << " " << j << " " << endl;
		}
			
		j --;
		if (j >= 0 && (a[j].first.first - b[i].first) * (a[j].first.first - b[i].first) + b[i].second * b[i].second <= a[j].first.second * a[j].first.second && ans[a[j].second] == -1) {
			ans[a[j].second] = i + 1;
			p ++;
			//cout << 735 << " " << i << " " << j << " " << endl;
		}
			
	}
	cout << p << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}