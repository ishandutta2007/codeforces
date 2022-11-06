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
#define inf 1000000000000000000LL

ll n, a, b, i;
ll v[maxN];
ll ans;

vector<ll> divs;
ll use[maxN];
ll sum[maxN];
ll best_l[maxN], best_r[maxN];

void compute(ll v) {
    for (int i = 2; i * i <= v; i++) {
        if (v % i == 0) {
            divs.pb(i);
            while (v % i == 0)
                v /= i;
        }
    }

    if (v > 1)
        divs.pb(v);
}

void solve(ll div) {
    int i;
    int min_bad = n + 1;
    int max_bad = 0;

    for (i = 1; i <= n; i++) {
        if (v[i] % div == 0)
            use[i] = 0;
        else
        if ( (v[i] - 1) % div == 0 || (v[i] + 1) % div == 0 )
            use[i] = b;
        else
            use[i] = -1; //! no chance

        sum[i] = sum[i - 1] + use[i];
    }

    for (i = 1; i <= n; i++) {
        if (use[i] < 0) {
            max_bad = i;
            min_bad = min(min_bad, i);
        }
    }

    for (i = 1; i < min_bad; i++)
        ans = min(ans, sum[i] + (n - i) * a);
    for (i = n; i > max_bad; i--)
        ans = min(ans, sum[n] - sum[i - 1] + (i - 1) * a);

    if (use[1] == -1 || use[n] == -1) return;

    best_l[1] = use[1] + a * (n - 1);
    for (i = 2; i < min_bad; i++)
        best_l[i] = min(best_l[i - 1], sum[i] + (n - i) * a);

    best_r[n] = use[n] - a;
    for (i = n - 1; i > max_bad; i--)
        best_r[i] = min(best_r[i + 1], sum[n] - sum[i - 1] - (n - i + 1) * a);

    if (max_bad != 0) { //! any bad pos
        ans = min(ans, best_l[min_bad - 1] + best_r[max_bad + 1]);
    } else { //!
        for (i = 1; i < n; i++)
            ans = min(ans, best_l[i] + best_r[i + 1]);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d%I64d%I64d", &n, &a, &b);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &v[i]);

    compute(v[1]);
    compute(v[1] - 1);
    compute(v[1] + 1);

    compute(v[n]);
    compute(v[n] - 1);
    compute(v[n] + 1);

    ans = inf;
    for (auto div : divs)
        solve(div);

    printf("%I64d", ans);

    return 0;
}