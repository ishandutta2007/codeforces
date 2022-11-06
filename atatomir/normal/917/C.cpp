#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 11
#define inf 1LL << 60

const int defK = 8;
const int pk = 1 << defK;
const int mask = pk - 1;

ll aux[pk][pk];
ll vv;

struct matrix {
    ll data[pk][pk];

    void init() {
        static int i, j;
        for (i = 0; i < pk; i++)
            for (j = 0; j < pk; j++)
                data[i][j] = inf;
    }

    matrix() {
        init();
    }

    void operator*=(matrix who) {
        static int i, j, k;

        memcpy(aux, data, sizeof(aux));

        for (i = 0; i < pk; i++)
            for (j = 0; j < pk; j++)
                data[i][j] = inf;

        for (k = 0; k < pk; k++) {
            for (i = 0; i < pk; i++) {
                if (aux[i][k] >= inf) continue;
                for (j = 0; j < pk; j++) {
                    data[i][j] = min(data[i][j], aux[i][k] + who.data[k][j]);
                }
            }
        }
    }

    void mult2(matrix& who) {
        static int i, j, k;

        memcpy(aux, data, sizeof(aux));

        for (i = 0; i < pk; i++)
            for (j = 0; j < pk; j++)
                data[i][j] = inf;

        for (k = 0; k < pk; k++) {
            for (i = 0; i < pk; i++) {
                if (aux[i][k] >= inf) continue;
                for (j = 0; j < pk; j++) {
                    data[i][j] = min(data[i][j], aux[i][k] + who.data[k][j]);
                }
            }
        }
    }

    void mult(matrix who) {
        static int i, j, k;

        memcpy(aux, data, sizeof(aux));

        for (i = 0; i < pk; i++)
            for (j = 0; j < pk; j++)
                data[i][j] = inf;

        for (k = 0; k < pk; k++) {
            for (i = vv; i <= vv; i++) {
                if (aux[i][k] >= inf) continue;
                for (j = 0; j < pk; j++) {
                    data[i][j] = min(data[i][j], aux[i][k] + who.data[k][j]);
                }
            }
        }
    }
};

matrix def[31];

int x, k, n, q, i, j, p;
ll c[maxN], pos, val;
map<ll, ll> M;
vector<ll> need;

matrix base;
matrix temp;

ll wh, to;
matrix act;

void make_base(matrix& base) {
    int conf, nxt, i;

    base.init();
    for (conf = 0; conf < pk; conf++) {
        nxt = conf << 1;

        //if (conf == 96)
        //    cerr << "d";

        if ( (nxt & pk) == 0) {
            base.data[conf][nxt] = 0;
        } else {
            nxt ^= pk;

            for (i = 0; i < defK; i++) {
                if (nxt & (1 << i)) continue;
                base.data[conf][nxt | (1 << i)] = c[8 - i];
            }
        }
    }
}

void make_temp(int r_pos) {
    int i;

    for (i = 1; i <= defK; i++) c[i] += M[r_pos - defK + i];
    make_base(temp);
    for (i = 1; i <= defK; i++) c[i] -= M[r_pos - defK + i];
}

void poww(matrix& sol, ll b) {
    int i;

    i = 0;
    while (b > 0) {
        if (b & 1) sol.mult(def[i]);
        b >>= 1;
        i++;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d", &x, &k, &n, &q);
    for (i = 1; i <= k; i++) scanf("%lld", &c[i]);
    for (i = 1; i <= q; i++) {
        scanf("%lld%lld", &pos, &val);
        M[pos] = val;
        for (j = 0; j < defK; j++) need.pb(pos + j);
    }

    while (k < defK) c[++k] = inf;

    make_base(base);

    def[0] = base;
    for (i = 1; i <= 30; i++) {
        def[i] = def[i - 1];
        def[i] *= def[i];
    }

    sort(need.begin(), need.end());
    need.resize(unique(need.begin(), need.end()) - need.begin());

    act.init();
    vv = ((1 << x) - 1) << (k - x);
    act.data[vv][vv] = 0;

    need.pb(n + 300);
    for (p = 0; need[p] <= k; p++);
    wh = k;

    while (wh < n + k - x) {
        if (need[p] == wh + 1) {
            make_temp(wh + 1);
            act.mult(temp);
            p++;
            wh++;
        } else {
            to = min(1LL * n + k - x, need[p] - 1);
            poww(act, to - wh);
            wh = to;
        }
    }

    printf("%lld", act.data[vv][vv]);

    return 0;
}