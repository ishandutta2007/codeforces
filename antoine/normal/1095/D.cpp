#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 2e5;

int a[MaxN + 9];
int b[MaxN + 9];

bool f(int u, int v) {
	return a[u] == v || b[u] == v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	if (n == 3) {
		cout << "1 2 3";
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i) {
		if (f(b[i], a[i]))
			swap(a[i], b[i]);
		assert(f(a[i], b[i]));
	}
	const int start = 1;
	int u = start;
	do {
		cout << u << ' ';
		u = a[u];
	} while (u != start);
	return 0;
}