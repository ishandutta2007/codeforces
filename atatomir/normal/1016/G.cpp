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

const int maxN = 200011;
const int limit = 1000000;
const int maxBit = 20;

ll n, X, Y, i, bts, max_conf;
ll a[maxN];
vector< pair<ll, ll> > divs, divs2, act;
vector<ll> to_check;

vector<ll> A, B;
ll data[1 << maxBit];
ll ans;

void give(ll x) {
    cout << x;
    exit(0);
}

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void fact(ll x) {
    ll i, cnt, aux;

    if (Y % X) give(0);

    for (i = 2; i * i <= x && i <= limit; i++) {
        if (x % i) continue;
        cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        divs.pb(mp(i, cnt));
    }

    if (x == 1) return;
    aux = llround(sqrt(x));
    if (aux * aux == x) {
        divs.pb(mp(aux, 2));
        return;
    }

    to_check.pb(X);
    to_check.pb(Y);
    for (auto e : to_check) {
        aux = gcd(e, x);
        if (aux == 1 || aux == x) continue;
        divs.pb(mp(aux, 1));
        divs.pb(mp(x / aux, 1));
        return;
    }

    divs.pb(mp(x, 1));
}

void fact_smart(ll x, vector< pair<ll, ll> >& to) {
    ll cnt, aux;

    to.clear();
    aux = x;

    for (auto e : divs) {
        cnt = 0;
        while (aux % e.first == 0) {
            cnt++;
            aux /= e.first;
        }
        to.pb(mp(e.first, cnt));
    }
}

void add_elem(ll x) {
    ll i, j, cnt, aux;
    ll conf, pos = 0;

    //! add X

    aux = x;
    conf = pos = 0;
    for (auto e : divs2) {
        cnt = 0;

        while (aux % e.first == 0) {
            cnt++;
            aux /= e.first;
        }

        if (cnt != e.second && e.second != divs[pos].second) conf |= 1 << pos;

        pos++;
    }
    if (x % X == 0) A.pb(conf);


    //! add Y

    aux = x;
    conf = pos = 0;
    for (auto e : divs) {
        cnt = 0;

        while (aux % e.first == 0) {
            cnt++;
            aux /= e.first;
        }

        if (cnt != e.second && e.second != divs2[pos].second) conf |= 1 << pos;

        pos++;
    }
    if (Y % x == 0) B.pb(conf);

}

void solve() {
    ll i, j;

    bts = divs.size();
    max_conf = 1 << bts;

    for (auto e : A) data[e]++;
    for (i = 0; i < bts; i++)
        for (j = 0; j < max_conf; j++)
            if ((j >> i) & 1)
                data[j] += data[j ^ (1 << i)];

    for (auto e : B)
        ans += data[(max_conf - 1) ^ e];

    give(ans);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> X >> Y;
    for (i = 1; i <= n; i++) cin >> a[i], to_check.pb(a[i]);

    fact(Y);
    fact_smart(X, divs2);
    for (i = 1; i <= n; i++) add_elem(a[i]);

    solve();


    return 0;
}