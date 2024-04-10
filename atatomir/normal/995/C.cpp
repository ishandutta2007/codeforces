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

const int maxN = 100011;
const ll D = 1000000LL;
const ll DD = D * D;

struct elem {
    ll x, y;
    double ang;
    vector<ll> norm, inv;
};

ll n, i, ss, dd, here, nxt, conf, limit;
ll x, y;
vector<elem> data[2];
vector<int> ord;

pair<ll, ll> best;
int tp[maxN];

bool cmp(int x, int y) {
    return data[ss][x].ang < data[ss][y].ang;
}

bool combine(elem& A, elem& B) {
    ll xx, yy;

    xx = A.x + B.x;
    yy = A.y + B.y;

    if (xx * xx + yy * yy <= DD) {
        A.x = xx;
        A.y = yy;
        for (auto e : B.norm) A.norm.pb(e);
        for (auto e : B.inv) A.inv.pb(e);
        A.ang = atan2(A.y, A.x);
        data[dd].pb(A);
        return true;
    }

    xx = A.x - B.x;
    yy = A.y - B.y;

    if (xx * xx + yy * yy <= DD) {
        A.x = xx;
        A.y = yy;
        for (auto e : B.norm) A.inv.pb(e);
        for (auto e : B.inv) A.norm.pb(e);
        A.ang = atan2(A.y, A.x);
        data[dd].pb(A);
        return true;
    }

    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    ss = 0; dd = 1;
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &x, &y);
        data[ss].pb({x, y, atan2(y, x), {i}, {}});
    }

    while (data[ss].size() > 10) {
        data[dd].clear();
        ord.clear();
        for (i = 0; i < data[ss].size(); i++) ord.pb(i);
        sort(ord.begin(), ord.end(), cmp);

        for (i = 0; i < ord.size(); i++) {
            if (i == ord.size() - 1) {
                data[dd].pb(data[ss][ord[i]]);
                break;
            }
            here = ord[i];
            nxt = ord[i + 1];
            if (combine(data[ss][here], data[ss][nxt])) {
                i++;
            } else {
                data[dd].pb(data[ss][here]);
            }
        }

        swap(ss, dd);
    }

    limit = (1LL << data[ss].size());
    best = mp(1LL << 60, 0);

    for (conf = 0; conf < limit; conf++) {
        x = y = 0;
        for (i = 0; i < data[ss].size(); i++) {
            if ((conf >> i) & 1) {
                x += data[ss][i].x;
                y += data[ss][i].y;
            } else {
                x -= data[ss][i].x;
                y -= data[ss][i].y;
            }
        }

        best = min(best, mp(x * x + y * y, conf));
    }

    conf = best.second;
    for (i = 0; i < data[ss].size(); i++) {
        if ((conf >> i) & 1) {
            for (auto e : data[ss][i].norm) tp[e] = 1;
            for (auto e : data[ss][i].inv) tp[e] = -1;
        } else {
            for (auto e : data[ss][i].norm) tp[e] = -1;
            for (auto e : data[ss][i].inv) tp[e] = 1;
        }
    }

    cerr << best.first << '\n';
    for (i = 1; i <= n; i++) printf("%d ", tp[i]);



    return 0;
}