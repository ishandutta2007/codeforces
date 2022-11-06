#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for (int i = a, i##end = b; i <= i##end; ++i)

bool check(ll p) {
	if (p <= 1) return false;
	rep(i, 2, sqrt(p))
		if (!(p%i)) return false;
	return true;
}

ll n;

int main() {
	scanf("%lld", &n);
	if (n==1||check(n)) printf("%lld", n);
	else {
		rep(i, 2, 1000000) {
			if (!check(i) || n%i) continue;
			while (!(n%i)) n/=i;
			printf("%d", n==1?i:1);
			break;
		}
	}
	return 0;
}