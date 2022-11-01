#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int N = 100005;

int n;
ll num, x, a[N];
set <pii> s;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		num ^= x;
		s.emplace(x, i);
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < 60; ++j) {
			if (num & 1LL << j) {
				auto it = s.lower_bound(pii(1LL << j, -1));
				ll x = (*it).first;
				if (x >= (1LL << (j + 1))) continue;
				num ^= x, s.erase(it), a[i] = x;
				break;			
			}
		}
		if (a[i] == 0) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", a[i]);
	}
	puts("");
	// for (int i = 1; i <= n; ++i) {
	// 	a[i] ^= a[i - 1];
	// 	printf("%lld ", a[i]);
	// }
	// puts("");
  return 0;
}