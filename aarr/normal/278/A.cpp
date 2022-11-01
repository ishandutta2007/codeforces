#include <iostream>
#include <algorithm>
using namespace std;

int d[105];
int main() {
	int n, s, t, ans = 0, sm = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		sm += d[i];
	}
	cin >> s >> t;
	if (s > t) {
		swap(s, t);
	}
	for (int i = s; i < t; i++) {
		ans += d[i];
	}
	cout << min(ans, sm - ans);
}