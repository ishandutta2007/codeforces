#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;

bool check(int t) {
	int nn = n - t * k;
	int nnn = nn;
	if (nn <= 0) return false;
	int cnt = 0;
	while (nn > 0) {
		cnt += nn % 2;
		nn /= 2;
	}
	if (cnt <= t && nnn >= t) return true;
	else return false;
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 50; i++) {
		if (check(i)) {
			return cout << i, 0;
		}
	}
	cout << -1;
	return 0;
}