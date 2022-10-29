#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

int n;
int c[66];
vector<ll> a[66];

int main() {
	ll x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		y = x;
		int p = 0;
		while (!(x & 1))
			x >>= 1, p++;
		c[p]++;
		a[p].push_back(y);
	}
	int mx = c[0], id = 0;
	for (int i = 1; i <= 63; i++) {
		if (c[i] > mx) {
			mx = c[i];
			id = i;
		}
	}
	printf("%d\n", n - mx);
	for (int i = 0; i <= 62; i++) {
		if (id ^ i) {
			for (auto z : a[i])
				printf("%lld ", z);
		}
	}
	return 0;
}