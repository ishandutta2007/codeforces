#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int b, p, f;
		cin >> b >> p >> f;
		int h, c;
		cin >> h >> c;
		int ans = 0;
		if (c > h) {
			swap(h, c);
			swap(p, f);
		}
		int cnt_a = min(b / 2, p);
		int cnt_b = min((b - 2 * cnt_a) / 2, f);
		cout << cnt_a * h + cnt_b * c << endl;
	}
}