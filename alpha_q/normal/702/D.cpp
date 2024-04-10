#include <bits/stdc++.h>

using namespace std;

long long d, k, a, b, t, res;

long long func (long long x) {
    return t * ((x - 1)/k) + a * x - b * x + b * d;
}

int main (int argc, char const *argv[]) {
//  freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);

    if (t >= k * (b - a)) {
        res = func(d);
        if (d > k) res = min(res, func(k));
    } else {
        res = func(d);
        if (d > k) res = min(res, func((d/k) * k));
    }

    printf("%lld\n", res);
	return 0;
}