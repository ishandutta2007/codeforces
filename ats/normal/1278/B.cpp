#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		int X = abs(A - B);
		int j = 0;
		while (X > 0) {
			j++;
			X -= j;
		}
		while ((-X) % 2 != 0) {
			j++;
			X -= j;
		}
		cout << j << "\n";
	}
	return 0;
}