#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long l, r;


long long f(long long x)
{
    long long y;
    y = x;

    int a[20];
    int n = 0;

    do a[n++] = 9 - x % 10; while (x /= 10);
    reverse(a, a + n);

    x = 0;
    for (int i = 0; i < n; i++)
        x = x * 10 + a[i];

    return x * y;
}

long long run(long long l, long long r)
{
    while (l < r)
    {
        long long
            lc = l + (r - l) / 3,
            rc = r - (r - l) / 3;

        if (f(lc) > f(rc))
            r = rc - 1;
        else
            l = lc + 1;
    }
    return f(l);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    cin >> l >> r;
    long long ans = 0;
    long long x = 1;
    while (x <= l) x *= 10;

    while (x <= r)
    {
        ans = max(ans, run(l, x - 1));
        l = x;
        x *= 10;
    }
    ans = max(ans, run(l, r));

    cout << ans << endl;
    return 0;
}