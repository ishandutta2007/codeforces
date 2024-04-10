#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 9;
int cs[MaxN + 9][2];
const int mod = (int) 1e9 + 7;
ll p2[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p2[0] = 1;
	for (int i = 1; i <= MaxN; ++i)
		p2[i] = p2[i - 1] * 2 % mod;

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j)
			cs[i][j] = cs[i - 1][j];
		char c;
		cin >> c;
		++cs[i][c - '0'];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;

		const int c0 = cs[r][0] - cs[l - 1][0];
		const int c1 = cs[r][1] - cs[l - 1][1];

		ll res = p2[c0] * (p2[c1] - 1) % mod;
		cout << (res % mod + mod) % mod << '\n';
	}
	return 0;
}