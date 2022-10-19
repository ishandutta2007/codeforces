#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll x;
		scanf("%lld", &x);
		puts(x % 14 >= 1 && x % 14 <= 6 && x >= 15 ? "YES" : "NO");
	}
	return 0;
}