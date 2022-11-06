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

const int maxN = 15;
const int maxDim = 500011;
const int maxW = 111;
const int limitW = 101;

int n, q, m, k, i, j, limit, sm, bg, sm_limit, bg_limit;
int w[maxN];
char s[maxN];

int cnt[1 << 12][maxW];
int help[1 << 12], help2[1 << 12];

void pre() {
    int conf, i, ans;

    for (conf = 0; conf < limit; conf++) {
        ans = 0;
        for (i = 0; i < sm; i++)
            if (((conf >> i) & 1) == 0)
                ans += w[i + 1];
        help[conf] = ans;

        ans = 0;
        for (i = sm; i < n; i++)
            if (((conf >> i) & 1) == 0)
                ans += w[i + 1];
        help2[conf] = ans;
    }
}

void add_elem() {
    int i, j, conf, val;

    val = 0;
    for (i = 1; i <= n; i++)
        val = (val * 2) + s[i] - '0';

    for (conf = 0; conf < sm_limit; conf++) {
        if (help[conf] > limitW) continue;
        cnt[val ^ conf][help[conf]]++;
    }

}

void post() {
    int i, j, conf;

    for (conf = 0; conf < limit; conf++)
        for (i = 1; i <= limitW; i++)
            cnt[conf][i] += cnt[conf][i - 1];
}

void solve() {
    int i, j, conf, aux_conf, val;
    int ans = 0;

    val = 0;
    for (i = 1; i <= n; i++) val = (val * 2) + s[i] - '0';

    for (aux_conf = 0; aux_conf < bg_limit; aux_conf++) {
        conf = (aux_conf << sm);

        if (help2[conf] > k) continue;
        ans += cnt[val ^ conf][k - help2[conf]];
    }

    printf("%d\n", ans);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &q, &m);
    for (i = 1; i <= n; i++) scanf("%d", &w[i]);
    reverse(w + 1, w + n + 1);
    scanf("\n");

    limit = 1 << n;
    sm = (n / 2);
    bg = n - sm;
    sm_limit = 1 << sm;
    bg_limit = 1 << bg;

    pre();
    for (i = 1; i <= q; i++) {
        scanf("%s\n", s + 1);
        add_elem();
    }
    post();

    for (i = 1; i <= m; i++) {
        scanf("%s%d\n", s + 1, &k);
        solve();
    }


    return 0;
}