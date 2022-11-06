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

#define maxN 200011
#define maxK 2016
#define maxNeed 24
#define mod 1000000007

#define inv(x) poww(x, mod - 2)

const int def = 22;

int n, m, s, k, i, j;
pair<int, int> pos[maxK];
ll dp[maxK][maxNeed];

ll fact[maxN];
ll inv_fact[maxN];

ll ans;


ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void prepare() {
    int i, cnt;
    cnt = 0;

    for (i = 1; i <= k; i++) {
        if (pos[i] == mp(1, 1) || pos[i] == mp(n, m)) {
            s -= (s >> 1);
            continue;
        }

        pos[++cnt] = pos[i];
    }

    k = cnt + 1;
    pos[0] = mp(1, 1);
    pos[k] = mp(n, m);

    sort(pos, pos + k + 1);


    fact[0] = 1;
    for (i = 1; i <= 200000; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    inv_fact[200000] = inv(fact[200000]);
    for (i = 199999; i > 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    inv_fact[0] = 1;

}

ll comb(ll n, ll m) {
    ll ans = (fact[n] * inv_fact[m]) % mod;
    return (ans * inv_fact[n - m]) % mod;
}

ll ways(int a, int b) {
    static ll dx, dy;

    dx = pos[b].first - pos[a].first;
    dy = pos[b].second - pos[a].second;

    return comb(dx + dy, dx);
}

void compute() {
    int i, j, to, cnt;

    dp[0][0] = 1;
    for (i = 0; i <= k; i++) {
        for (j = 1; j <= def; j++) dp[i][j] %= mod;
        for (j = 1; j < def; j++) {
            dp[i][j] += mod - dp[i][j + 1];
            dp[i][j] %= mod;
        }

        for (j = 0; j <= def; j++) {
            if (dp[i][j] == 0) continue;

            cnt = min(def, j + 1);

            for (to = i + 1; to <= k; to++) {
                if (pos[i].second > pos[to].second) continue;

                dp[to][cnt] += (dp[i][j] * ways(i, to)) % mod;
            }
        }
    }
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (i = 1; i <= k; i++) scanf("%d%d", &pos[i].first, &pos[i].second);

    prepare();
    compute();

    for (i = 1; i <= def; i++) {
        ans += s * dp[k][i];
        ans %= mod;

        s -= (s >> 1);
    }

    ans *= inv(comb(n - 1 + m - 1, n - 1));
    ans %= mod;

    printf("%lld", ans);


    return 0;
}