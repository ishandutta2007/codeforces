#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011

int n, k, i, x, l, r;
int aib[maxN];
ll ans;

int zrs(int x) {
    return (x ^(x - 1)) & x;
}

void add(int pos, int v) {
    while (pos <= n) {
        aib[pos] += v;
        pos += zrs(pos);
    }
}

int sum(int pos) {
    int ans = 0;

    while (pos > 0) {
        ans += aib[pos];
        pos -= zrs(pos);
    }

    return ans;
}

int intr(int x, int y) {
    return sum(y + 1) - sum(x);
}

int main()
{

    scanf("%d%d", &n, &k);
    x = 0;

    k = min(k, n - k);

    ans = 1;
    for (i = 1; i <= n; i++) {
        l = x + 1;
        r = x + k - 1;

        l %= n;
        r %= n;

        if (l <= r)
            ans += 1LL * intr(l, r);
        else
            ans += 1LL * intr(l, n - 1) + intr(0, r);

        add(x + 1, +1);
        x = (x + k) % n;
        add(x + 1, +1);

        ans++;
        printf("%lld ", ans);
    }


    return 0;
}