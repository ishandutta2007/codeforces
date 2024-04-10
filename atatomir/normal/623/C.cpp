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

#define maxN 100011
#define xx P[i].first
#define yy P[i].second

int n, i;
pair<ll, ll> P[maxN];

ll min_l[maxN];
ll max_l[maxN];
ll min_r[maxN];
ll max_r[maxN];

ll moddo(ll x) {
    if (x > 0)
        return x;
    return -x;
}

bool good(ll dist) {
    int l, r;
    ll mini, maxi;
    bool is_good = false;

    r = 1;
    for (l = 1; l <= n; l++) {
        //! i know it is too long..
        while ( r + 1 <= n && (P[r + 1].first - P[l].first) * (P[r + 1].first - P[l].first) <= dist && moddo(P[l].first) >= moddo(P[r + 1].first)) r++;

        mini = 1LL << 62;
        maxi = -mini;

        if (l != 1) {
            mini = min_l[l - 1];
            maxi = max_l[l - 1];
        }

        if (r != n) {
            mini = min(mini, min_r[r + 1]);
            maxi = max(maxi, max_r[r + 1]);
        }

        if (mini == (1LL << 62)) {
            is_good = true;
        } else {
            ll aux = P[l].first * P[l].first + mini * mini;
            if (aux > dist) continue;
            aux = P[l].first * P[l].first + maxi * maxi;
            if (aux > dist) continue;

            aux = P[r].first * P[r].first + mini * mini;
            if (aux > dist) continue;
            aux = P[r].first * P[r].first + maxi * maxi;
            if (aux > dist) continue;

            aux = (maxi - mini) * (maxi - mini);
            if (aux > dist) continue;

            is_good = true;
        }

    }

    return is_good;
}

ll try_it() {
    int i;

    min_l[1] = max_l[1] = P[1].second;
    for (i = 2; i <= n; i++) {
        min_l[i] = min(min_l[i - 1], yy);
        max_l[i] = max(max_l[i - 1], yy);
    }

    min_r[n] = max_r[n] = P[n].second;
    for (i = n - 1; i > 0; i--) {
        min_r[i] = min(min_r[i + 1], yy);
        max_r[i] = max(max_r[i + 1], yy);
    }

    ll ans = -1;
    for (ll step = (1LL << 62); step > 0; step >>= 1)
        if (!good(ans + step))
            ans += step;

    ll diam = max_l[n] - min_l[n];

    return min(diam * diam, ans + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld%lld", &P[i].first, &P[i].second);

    sort(P + 1, P + n + 1);

    ll ans = try_it(); //! x, y

    for (i = 1; i <= n; i++) P[i].first *= -1;
    reverse(P + 1, P + n + 1);
    ans = min(ans, try_it()); //! -x, y

    for (i = 1; i <= n; i++) P[i].first *= -1;
    for (i = 1; i <= n; i++) swap(P[i].first, P[i].second);
    sort(P + 1, P + n + 1);
    ans = min(ans, try_it()); //! y, x

    for (i = 1; i <= n; i++) P[i].first *= -1;
    reverse(P + 1, P + n + 1);
    ans = min(ans, try_it()); //! -y, x

    printf("%lld", ans);

    return 0;
}