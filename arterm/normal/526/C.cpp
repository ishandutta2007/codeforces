#include <bits/stdc++.h>

using namespace std;

#define long long long
const long B = 100500;

long h1, h2, w1, w2, c;

long up(long x) {
	long ans = 0;
	for (long i = 0; i <= x; ++i) {
		ans = max(ans, i * h1 + ((c - w1 * i) / w2) * h2);
	}
	return ans;
}

int main() {
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (w1 < w2) {
		swap(w1, w2);
		swap(h1, h2);
	}

	long ans = 0;
	if (c / w1 <= B)
		ans = up(c / w1);
	else {
		ans = up(max(w1, w2));
		swap(w1, w2);
		swap(h1, h2);
		ans = max(ans, up(max(w1, w2)));
	}

	cout << ans << "\n";
	return 0;
}