#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void minimize(int &x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, b, a;
	cin >> n >> b >> a;

	vector<int> s(n);
	for (int &x : s)
		cin >> x;

	const int A = a;

	int i = 0;

	for (; (b || a) && i < n; i++) {
		if (!a || (s[i] && b && a < A)) {
			b--;
			minimize(a += s[i], A);
		} else
			a--;
	}
	cout << i;
	return 0;
}