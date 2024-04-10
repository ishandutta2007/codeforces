#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 1e5 + 9;
int p[MxN + 9];
int c[MxN + 9];
int cnt[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, root;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		c[i] ^= 1;
	}

	for (int i = 1; i <= n; ++i) {
		cnt[i] += c[i];
		if (p[i] != -1)
			cnt[p[i]] += c[i];
	}

	bool ok = false;

	for (int i = 1; i <= n; ++i)
		if (!cnt[i] && p[i] != -1) {
			cout << i << ' ';
			ok = true;
		}

	if (!ok)
		cout << -1;

	return 0;
}