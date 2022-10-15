#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

ll n;

bool check(ll k) {
    ll c1 = 0, c2 = 0;
    ll cnt = n;
    while (cnt) {
        c1 += min(cnt, k);
        if (cnt > k) cnt -= k;
        else cnt = 0;
        c2 += cnt / 10;
        cnt -= cnt / 10;
    }
    return c1 >= c2;
}

int main() {
    boost();

    cin >> n;
    ll lo = 1, hi = 1e18, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    printf("%lld\n", lo);

    return 0;
}