#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	if (n > k * (k - 1LL)) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";

	for (int diff = 1; diff < k; ++diff) {
		for (int j = 1; j + diff <= k; ++j) {
			const int i = j + diff;
			cout << i << ' ' << j << '\n';
			if (!--n)
				return 0;
		}
		for (int j = k; j - diff >= 1; --j) {
			const int i = j - diff;
			cout << i << ' ' << j << '\n';
			if (!--n)
				return 0;
		}
	}
	return 0;
}