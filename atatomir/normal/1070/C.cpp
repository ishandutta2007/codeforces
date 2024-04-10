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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 1000111;
const int sz = 1000011;

struct aib {
    ll data[maxN];
    ll n;

    void init(ll _n) {
        n = _n;
        for (ll i = 1; i <= n; i++)
            data[i] = 0;
    }

    ll zrs(ll x) {
        return (x ^ (x - 1)) & x;
    }

    void add(ll x, ll v) {
        while (x <= n) {
            data[x] += v;
            x += zrs(x);
        }
    }

    ll src(ll x) {
        ll ans = 0;
        for (ll step = 1 << 20; step > 0; step >>= 1)
            if (ans + step <= n)
                if (data[ans + step] < x)
                    x -= data[ans + step], ans += step;
        return ans;
    }

    ll sum(ll x) {
        ll ans = 0;
        while (x > 0) {
            ans += data[x];
            x -= zrs(x);
        }
        return ans;
    }
};

ll n, k, m, i, j;
ll l, r, c, p;
vector< pair<ll, ll> > upd[maxN];
aib cnt, sum;
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &k, &m);
    cnt.init(sz);
    sum.init(sz);

    for (i = 1; i <= m; i++) {
        scanf("%lld%lld%lld%lld", &l, &r, &c, &p);
        upd[l].pb(mp(c, p));
        upd[r + 1].pb(mp(-c, p));
    }

    for (i = 1; i <= n; i++) {
        for (auto e : upd[i]) {
            cnt.add(e.second, e.first);
            sum.add(e.second, e.first * e.second);
        }

        if (cnt.sum(sz) <= k) {
            ans += sum.sum(sz);
            continue;
        }

        ll pos = cnt.src(k);
        ll cnt_bef = cnt.sum(pos);
        ll sum_bef = sum.sum(pos);

        ans += sum_bef + (k - cnt_bef) * (pos + 1);
    }

    printf("%lld", ans);

    return 0;
}