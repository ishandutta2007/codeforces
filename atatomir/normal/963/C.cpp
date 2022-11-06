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

const int maxN = 200011;

ll n, i, j, cntx, cnty, x, y, z;
ll vx[maxN];
map<ll, ll> Mx, My;
map< pair<ll, ll>, ll > M;
pair<ll, pair<ll, ll> > low;

vector< vector<ll> > data;
vector<ll> le, ri;
vector<ll> vals;

bool check_rat() {
    int i, j;

    for (i = 1; i + 1 <= cntx; i++) {
        for (j = 1; j + 1 <= cnty; j++) {
            if (data[i][j] * data[i + 1][j + 1] != data[i + 1][j] * data[i][j + 1])
                return false;
        }
    }

    return true;
}

void check(ll d) {
    ll i, j;

    le[1] = d;
    for (i = 1; i <= cnty; i++) {
        if (data[1][i] % d) return;
        ri[i] = data[1][i] / d;
    }

    for (i = 1; i <= cntx; i++) {
        if (data[i][1] % ri[1]) return;
        le[i] = data[i][1] / ri[1];
    }

    /*
    for (i = 1; i <= cntx; i++)
        for (j = 1; j <= cnty; j++)
            if (le[i] * ri[j] != data[i][j])
                return;
    */

    ll aux = 0;
    for (i = 1; i <= cntx; i++)
        aux += le[i] * vx[i];

    vals.pb(aux);
}

int main()
{
    //freopen("test.in","r",stdin);

    low = mp(1LL << 60, mp(0, 0));

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        if (Mx[x] == 0) Mx[x] = ++cntx, vx[cntx] = x;
        if (My[y] == 0) My[y] = ++cnty;
        M[mp(Mx[x], My[y])] = z;
    }

    if (cntx * cnty != n) {
        printf("0");
        return 0;
    }

    le.resize(cntx + 1);
    ri.resize(cnty + 1);
    data = vector< vector<ll> > (cntx + 1, vector<ll>(cnty + 1, 0));
    for (i = 1; i <= cntx; i++)
        for (j = 1; j <= cnty; j++)
            data[i][j] = M[mp(i, j)];

    if (!check_rat()) {
        printf("0");
        return 0;
    }

    for (ll d = 1; d * d <= data[1][1]; d++) {
        if (data[1][1] % d) continue;
        check(d);
        if (d * d != data[1][1]) check(data[1][1] / d);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    printf("%d", vals.size());

    return 0;
}