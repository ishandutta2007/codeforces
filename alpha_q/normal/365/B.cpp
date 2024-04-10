#include <bits/stdc++.h>

using namespace std;

const long long M = 100005;

int main() {
	long long n, A[M], i, cnt, ret; cin >> n;
	for (i = 1; i <= n; i++) cin >> A[i];
	if (n == 1 || n == 2) {cout << n; return 0;}
	cnt = 2, ret = 2;
	for (i = 3; i <= n; i++) {
		if (A[i] == A[i - 1] + A[i - 2]) ++cnt;
		else ret = max(ret, cnt), cnt = 2;
	} ret = max(ret, cnt); cout << ret;
	return 0;
}