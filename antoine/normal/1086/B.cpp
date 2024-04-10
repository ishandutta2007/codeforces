#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int deg[(int) 1e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		++deg[a], ++deg[b];
	}

	const int cnt = count(deg, deg + n + 1, 1);
	cout << 2*double(s) / cnt;
	return 0;
}