#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	if(a == b) printf("%lld\n", 2 * (c + a));
	else printf("%lld\n", 2 * (min(a, b) + c) + 1);
	return 0;
}