#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, i, A[105]; cin >> n;
	for (i = 1; i <= n; i++) cin >> A[i];
	long long cnt = 0, ret = 1, start, end;
	for (i = 1; i <= n; i++) if (A[i] == 1) {start = i; break;}
	if (i == n + 1) {cout << 0 << endl; return 0;}
	for (i = n; i >= 1; i--) if (A[i] == 1) {end = i; break;}
	for (i = start + 1; i <= end; i++) {
		if (A[i] == 0) ++cnt;
		else {
			ret *= (cnt + 1);
			cnt = 0;
		}
	}
	cout << ret << endl;
	return 0;
}