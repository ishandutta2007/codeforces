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

const int maxN = 55;
const ll inf = 1LL << 60;

struct group {
    ll cnt, ener;
    vector<ll> proc;
};

ll n, i, j, k, m;
pair<ll, ll> data[maxN];
group grps[maxN];

ll dp[maxN][maxN];

void upd(ll& a, ll b) {
    if (a > b) a = b;
}

bool check(ll thres) {
    ll i, j, k;

    for (i = 0; i <= m; i++)
        for (j = 0; j <= n; j++)
            dp[i][j] = inf;

    dp[0][0] = 0;
    for (i = 0; i < m; i++) {
        auto& act = grps[i + 1];

        for (j = 0; j <= n; j++) {
            if (dp[i][j] >= inf) continue;

            for (k = max(0LL, act.cnt - j); k <= act.cnt; k++) {
                upd(dp[i + 1][j + k - (act.cnt - k)], dp[i][j] + act.ener * k - act.proc[k] * thres);
            }
        }
    }


    for (i = 0; i <= n; i++)
        if (dp[m][i] <= 0)
            return true;

    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &data[i].first), data[i].first *= 1000LL;
    for (i = 1; i <= n; i++) scanf("%lld", &data[i].second);

    sort(data + 1, data + n + 1);
    reverse(data + 1, data + n + 1);

    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (data[i].first != data[j].first)
                break;

        m++;
        grps[m].cnt = j - i;
        grps[m].ener = data[i].first;
        grps[m].proc = {0};

        for (k = i; k < j; k++)
            grps[m].proc.pb(grps[m].proc.back() + data[k].second);
    }

    ll ans = 0;
    for (ll step = 1LL << 45; step > 0; step >>= 1) {
        if (!check(ans + step))
            ans += step;
    }

    printf("%lld", ans + 1);


    return 0;
}