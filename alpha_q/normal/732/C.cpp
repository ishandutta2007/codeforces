#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main (int argc, char const *argv[]) {
	scanf("%lld %lld %lld", a, a + 1, a + 2);
	sort(a, a + 3);
	a[2] -= a[0], a[1] -= a[0], a[0] = 0;
	if (a[1] == a[2]) printf("%lld\n", max(0LL, a[1] - 1LL));
	else printf("%lld\n", max(0LL, a[2] + a[2] - a[1] - 2LL));
    return 0;
}