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

const int sz = 65;
const int max_bts = 11;

struct op {
    ll base, pos;
    int id;
    ll sgn;
};

int q, i, j;
ll b, l, r;
ll ans[maxN];
vector<op> ord;

ll pre[sz + 11][1 << max_bts];
vector<ll> aux;

ll solve(ll base, ll pos) {
    ll ans = 0;
    ll conf = 0;
    ll i, dim;

    aux.clear();
    while (pos > 0) {
        aux.pb(pos % base);
        pos /= base;
    }

    reverse(aux.begin(), aux.end());
    dim = aux.size();

    for (auto e : aux) {
        dim--;

        if (dim != aux.size() - 1) {
            for (i = 1; i < base; i++)
                ans += pre[dim][1 << i];
        }

        for (i = 0; i < e; i++) {
            if ( (dim == aux.size() - 1) && i == 0 ) continue;
            ans += pre[dim][conf ^ (1 << i)];
        }

        conf ^= (1 << e);
    }

    return ans;
}

void solve_bucket(int l, int r) {
    ll i, j, conf, lim;
    ll base = ord[l].base;

    lim = 1 << base;

    memset(pre, 0, sizeof(pre));
    pre[0][0] = 1;
    for (i = 0; i < sz; i++) {
        for (conf = 0; conf < lim; conf++) {
            if (pre[i][conf] == 0) continue;

            for (j = 0; j < base; j++) {
                pre[i + 1][conf ^ (1 << j)] += pre[i][conf];
            }
        }
    }

    for (i = l; i <= r; i++) {
        auto act = ord[i];

        ans[act.id] += act.sgn * solve(act.base, act.pos);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> b >> l >> r;
        ord.pb({b, r + 1, i, +1});
        ord.pb({b, l, i, -1});
    }

    sort(ord.begin(), ord.end(), [](const op& a, const op& b)->bool const {
        return a.base < b.base;
    });

    for (i = 0; i < ord.size(); i = j) {
        for (j = i; j < ord.size(); j++)
            if (ord[i].base != ord[j].base)
                break;

        solve_bucket(i, j - 1);
    }

    for (i = 1; i <= q; i++)
        cout << ans[i] << '\n';

    return 0;
}