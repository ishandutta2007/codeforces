#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	ll ans = 2ll * (c + min(a, b));
	if (a ^ b)
		ans++;
	printf("%lld\n", ans);
	return 0;
}