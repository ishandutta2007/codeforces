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

int t, ti;
ll n1, n2, n3, n;
ll m1, m2, m3, m;
ll s1, s2, s3, s;

vector<ll> aux;
vector< pair<ll, int> > gr, gr2;
vector<ll> ds;
ll ans;

void get_divs(vector<ll> data, vector< pair<ll, int> >& gr) {
    ll i, j;

    aux.clear();
    for (ll &e : data) {
        for (i = 2; i * i <= e; i++)
            while (e % i == 0)
                e /= i, aux.pb(i);
        if (e != 1) aux.pb(e);
    }

    gr.clear();
    sort(aux.begin(), aux.end());
    for (i = 0; i < aux.size(); i = j) {
        for (j = i; j < aux.size(); j++)
            if (aux[i] != aux[j])
                break;

        gr.pb(mp(aux[i], j - i));
    }
}

void _back(int step, ll act) {
    if (step == gr.size()) {
        ds.pb(act);
        return;
    }

    for (int i = 0; i <= gr[step].second; i++) {
        _back(step + 1, act);
        act *= -gr[step].first;
    }
}

ll abss(ll x) {
    if (x < 0)
        return -x;
    return x;
}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a);
        b >>= 1;
        a = (a * a);
    }

    return ans;
}

vector<ll> get_bad(vector< pair<ll, int> >& nn, vector< pair<ll, int> >& ss) {
    vector< pair<ll, int> > aux = {};
    ll i, j;
    vector<ll> ans = {};

    for (auto e : nn) aux.pb(e);
    for (auto e : ss) aux.pb(mp(e.first, -e.second));

    sort(aux.begin(), aux.end());
    for (i = 0; i < aux.size(); i = j) {
        auto act = aux[i];

        for (j = i + 1; j < aux.size(); j++) {
            if (aux[i].first != aux[j].first) break;
            act.second += aux[j].second;
        }

        if (act.second > 0) {
            if (i + 1 == j)
                ans.pb(act.first);
            else
                ans.pb(poww(act.first, -aux[i].second + 1));
        }
    }

    return ans;
}

ll solve() {
    ll i, j;

    aux.clear();
    gr.clear();
    ds.clear();

    //! stage 2
    get_divs({s1, s2, s3}, gr);
    _back(0, 1);

    ans = 0;
    for (auto e : ds)
        if (abss(e) <= n)
            ans++;

    get_divs({n1, n2, n3}, gr2);

    //! stage 1
    auto bad = get_bad(gr2, gr);

    int sgn = +1;
    int limit = 1 << bad.size();
    for (i = 0; i < limit; i++, sgn *= -1) {
        int conf = (i ^ (i >> 1));

        ll act = 1;
        for (j = 0; j < bad.size(); j++)
            if (conf & (1 << j))
                act = min(m + 1, act * bad[j]);

        ans += sgn * m / act;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%lld%lld%lld", &n1, &n2, &n3); n = n1 * n2 * n3;
        scanf("%lld%lld%lld", &m1, &m2, &m3); m = m1 * m2 * m3;
        scanf("%lld%lld%lld", &s1, &s2, &s3); s = s1 * s2 * s3 * 2LL; s1 *= 2LL;

        printf("%lld\n", solve()) ;
    }


    return 0;
}