#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const ll p = 17239169;

ll n, i, j;
vector<ll> m;
vector<ll> hh;
bool viv = false;

ll rrand() {
    ll res = 0;
    vector<ll> v;
    for (ll i = 0; i < 10; i++)
        v.push_back(rand() % kk);
    for (ll i = 0; i < v.size(); i += 2)
        res *= v[i], res += v[i+1], res %= mod;
    return res;
}

void prepare() {
    for (ll i = 0; i < 10*kk; i++)
        hh.push_back(rrand());
}

vector<ll> check(ll val, ll cf) {
    vector<ll> v;
    for (auto i : m)
        v.push_back(__builtin_popcount(i) * cf - __builtin_popcount(i ^ val));
    for (ll i = 1; i < v.size(); i++)
        v[i] -= v[0];
    v[0] = 0;
    return v;
}

ll has(vector<ll> v, ll cf) {
    for (auto &i : v)
        i *= cf;
    ll res = 0;
    for (ll i = 0; i < n; i++)
        v[i] += hh[i] % 1000;
    for (ll i = 0; i < n; i++) {
        res *= p;
        res += hh[v[i] + 100];
        res %= mod;
    }
    return res;
}

void answer(ll ans) {
    if (viv)
        cout << "Check " << ans << endl;
    vector<ll> v;
    for (auto &i : m)
        v.push_back((i ^ ans));
    if (viv) {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }
    set<ll> s;
    for (auto i : v)
        s.insert(__builtin_popcount(i));

    if (s.size() > 1)
        return;
    cout << ans << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(0));
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    vector<pll> ans1, ans2;
    prepare();
    for (ll i = 0; i < (1ll << 15); i++)
        ans1.push_back({has(check(i, 0), 1), i});
    for (ll i = 0; i < (1ll << 15); i++)
        ans2.push_back({has(check(i << 15, 1), -1), i << 15});

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());


    ll i = 0;
    ll j = 0;
    while (i < ans1.size() && j < ans2.size()) {
        if (ans1[i].F == ans2[j].F) {
            answer(ans2[j].S + ans1[i].S);
            i++, j++;
        }
        if (ans1[i].F < ans2[j].F)
            i++;
        else {
            if (ans1[i].F > ans2[j].F)
                j++;
        }
    }

    cout << -1 << endl;

    return 0;
}