#include <bits/stdc++.h>

using namespace std;

long long compute_sqrt(long long v)
{
    long long s = 0, e = 1'000'000'001;
    while (s < e) {
        long long mid = (s + e + 1) / 2;
        if (mid * mid <= v) {
            s = mid;
        } else {
            e = mid - 1;
        }
    }

    return s;
}

long long count_square(long long l, long long r) {
    return compute_sqrt(r) - compute_sqrt(l - 1);
}

void solve()
{
    long long l, r;
    scanf("%lld %lld", &l, &r);

    long long ans = count_square(l, r) + count_square(l + 1, r + 1);
    ans += max(count_square(l, r) - 1, 0LL);

    long long v = compute_sqrt(r);
    if (v * (v + 1) <= r && v * (v + 1) >= l) {
        ans++;
    }

    long long old_v = v;
    v = compute_sqrt(l - 1);
    
    if (old_v != v && v * (v + 1) <= r && v * (v + 1) >= l) {
        ans++;
    }

    printf("%lld\n", ans);
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}