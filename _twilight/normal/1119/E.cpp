#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll ans;

int main() {
	int rest = 0, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		int t = x / 3;
		x -= t * 3;
		ans += t;
		if (x == 2 && rest)
			rest--, x = 0, ans++;
		if (x == 1 && t && rest >= 2)
			rest -= 2, t--, x = 0, ans++;
		int need = rest / 3;
		int used = min((t >> 1) << 1, need << 1) >>1;
		rest -= used * 3;
		ans += used;
		rest += x;
	}
	printf("%lld\n", ans);
	return 0;
}