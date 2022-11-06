#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int p[(int) 1e5 + 9];
int sz[(int) 1e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		sz[i] = 1;

	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		sz[p[i]] = 0;
	}

	for (int i = n; i >= 2; --i)
		sz[p[i]] += sz[i];

	sort(sz + 1, sz + 1 + n);

	for (int i = 1; i <= n; ++i)
		cout << sz[i] << ' ';
	return 0;
}