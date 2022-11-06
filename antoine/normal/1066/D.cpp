#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int a[(int) 2e5 + 999];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = n - 1; i >= 0; --i)
		cin >> a[i];

	int curr = 0;
	for(int i = 0; i < n; ++i) {
		if((curr += a[i]) > k) {
			curr = a[i];
			if(--m <= 0) {
				cout << i;
				return 0;
			}
		}
		assert(curr <= k);
	}
	cout << n;
	return 0;
}