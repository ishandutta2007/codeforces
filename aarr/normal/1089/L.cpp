#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int b[N];
int c[N];
int d[N];
pair <int, int> e[N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		e[i] = {b[i], a[i]};
	}
	sort(e + 1, e + n + 1);
	int x = 0;
	for (int i = 1; i <= k; i++) {
		if (d[i] == 0)
			x++;
	}
	long long ans = 0;
	for (int i = 1; i <= n && x; i++) {
		if (c[e[i].second] != d[e[i].second] - 1) {
			c[e[i].second]++;
			ans += e[i].first;
		//	cout << e[i].first << " " << e[i].second << endl;
			x--;
		}
	}
	cout << ans;
	return 0;
}