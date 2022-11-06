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

int n, m, q, i;
ll a[maxN], b[maxN], sums[maxN];
ll def, l, r, c;

vector<ll> ord;

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

ll ask() {
    ll ans = 1LL << 60;

    auto it = lower_bound(ord.begin(), ord.end(), def);
    if (it != ord.end()) {
        ans = abss(def - *it);
    }

    if (it != ord.begin()) {
        it--;
        ans = min(ans, abss(def - *it));
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) def += a[i];
        else       def -= a[i];
    }


    for (i = 1; i <= m; i++) {
        cin >> b[i];
        if (i % 2 == 0) b[i] *= -1;
        sums[i] = b[i] + sums[i - 1];
    }

    for (i = 1; i + n - 1 <= m; i++)
        ord.pb((sums[i + n - 1] - sums[i - 1]) * (i % 2 == 1 ? 1 : -1));

    sort(ord.begin(), ord.end());

    printf("%lld\n", ask());
    for (i = 1; i <= q; i++) {
        scanf("%lld%lld%lld", &l, &r, &c);
        if ( (r - l + 1) % 2 == 1) {
            if (l % 2 == 1)
                def += c;
            else
                def -= c;
        }

        printf("%lld\n", ask());
    }


    return 0;
}