#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 10010;
int a[N];

int main() {
	int n = nxt(), k = nxt();
	for (int i = 0; i < n; ++i) {
		a[nxt()] += 1;
	}

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (__builtin_popcount(i ^ j) == k) {
				ans += 1ll * a[i] * a[j];
			}
		}
		if (k == 0) {
			ans += 1ll * a[i] * (a[i] - 1) / 2;
		}
	}
	
	cout << ans << "\n";

	return 0;
}