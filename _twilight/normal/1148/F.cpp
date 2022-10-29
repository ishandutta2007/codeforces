#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 3e5 + 5;

int n;
int v[N];
ll msk[N];

int main() {
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%lld", v + i, msk + i);
		sum += v[i];
	}
	if (sum < 0) {
		sum = -sum;
		for (int i = 1; i <= n; i++)
			v[i] = -v[i];
	}
	ll ans = 0;
	for (int b = 0; b <= 62; b++) {
		ll s = 0;
		for (int i = 1; i <= n; i++) {
			if ((msk[i] >> b) == 1) {
				s += v[i];
			} 
		}
		if (s > 0) {
			ans = ans | (1ll << b);
			for (int i = 1; i <= n; i++) {
				if ((msk[i] >> b) & 1) {
					v[i] = -v[i];
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}