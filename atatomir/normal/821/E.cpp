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

#define mod 1000000007

const int def = 15;

ll aux[def + 2][def + 2];

struct matrix {
    ll data[def + 2][def + 2];
    ll i, j, k;

    void init() {
        memset(data, 0, sizeof(data));
    }

    void operator*=(const matrix who) {
        memcpy(aux, data, sizeof(data));

        for (i = 0; i <= def; i++) {
            for (j = 0; j <= def; j++) {
                data[i][j] = 0;
                for (k = 0; k <= def; k++) data[i][j] += (aux[i][k] * who.data[k][j]) % mod;
                data[i][j] %= mod;
            }
        }
    }
};

ll n, k, i, j, l;
ll a, b, c;
matrix pre[def + 2];
vector< pair<ll, ll> > ord;
matrix ans;

matrix poww(matrix a, ll b) {
    matrix ans = a;
    b--;

    while (b > 0) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }

    return ans;
}

void rm(matrix& data, int limit) {
    int i, j;

    for (i = 0; i <= def; i++)
        for (j = limit + 1; j <= def; j++)
            data.data[i][j] = 0;

    for (i = 1; i <= def; i++)
        for (j = 1; j <= def; j++)
            data.data[i][j] = 0;
}

int main()
{
    //freopen("test.in","r",stdin);

    for (i = 0; i <= def; i++) {
        pre[i].init();
        for (j = 0; j <= i; j++) {
            if (j != 0) pre[i].data[j][j - 1] = 1;
            pre[i].data[j][j] = 1;
            if (j != i) pre[i].data[j][j + 1] = 1;
        }
    }

    ans.init();
    ans.data[0][0] = 1;

    scanf("%lld%lld", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        b = min(b, k);
        ord.pb(mp(c, b - a));
    }

    reverse(ord.begin(), ord.end());

    for (i = ord.size() - 1; i >= 0; i--) {
        auto act = ord[i];

        if (act.second >= 1) ans *= poww(pre[act.first], act.second);
        if (i != 0) rm(ans, ord[i - 1].first);
    }

    cout << ans.data[0][0];


    return 0;
}