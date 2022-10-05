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


ll n, i, j, a, b, c;
vector<ll> m;
multiset<ll, greater<ll>> s;
bool viv = false;

ll _triple() {
    ll res = 0;
    while (s.size() && (*s.begin()) > b + c) {
        s.erase(s.begin());
        res++;
    }
    return res;
}

ll _double() {
    ll res = 0;
    while (s.size() && (*s.begin()) > c) {
        ll p = *s.begin();
        ll ost = -1;
        if (a + b >= p)
            ost = c;
        else
            if (a + c >= p)
                ost = b;
            else
                if (b + c >= p)
                    ost = a;
        if (ost == -1) {
            while (true && (a == a + 0)) {
                cout << "SHIIIIIIT" << endl;
            }
        }
        s.erase(s.begin());
        auto z = s.lower_bound(ost);
        if (z != s.end())
            s.erase(z);
        res++;
    }
    return res;
}

void check(ll val) {
    auto z = s.lower_bound(val);
    if (z != s.end())
        s.erase(z);
}

ll _ones() {
/**
    while (s.size()) {
        check(c);
        check(b);
        check(a);
        res++;
    }
**/

    ll d = b + a;
    d = min(d, c);

    ll kc, kd, kb, ka;
    kc = kd = kb = ka = 0;
    while (s.size() && (*s.begin()) > d) {
        kc++;
        s.erase(s.begin());
    }
    while (s.size() && (*s.begin()) > b) {
        kd++;
        s.erase(s.begin());
    }
    while (s.size() && (*s.begin()) > a) {
        kb++;
        s.erase(s.begin());
    }
    while (s.size()) {
        ka++;
        s.erase(s.begin());
    }
    if (viv)
        cout << "Oh, " << kc << ' ' << kd << ' ' << kb << ' ' << ka << endl;
    ll ans = inf;
    for (ll i = 0; i <= kd; i++) {
        if (viv)
            cout << "Checking " << kd << endl;
        ll res = 0;
        ll lka = ka;
        ll lkb = kb;
        ll lkc = kc;
        ll lkd = kd;
        ll l = i;

        lkd -= l;
        lkc += lkd;
        lkd = 0;
        ll v = l;
        ll u = min(v, lkc);
            lkc -= u, v -= u;
        u = min(v, lkb);
            lkb -= u, v -= u;
        u = min(v, lka);
            lka -= u, v -= u;
        res += l;

        v = min(lkc, min(lka, lkb));
        res += v;
        lka -= v;
        lkb -= v;
        lkc -= v;

        if (lkc == 0) {
            if (2 * lka < lkb) {
                res += lka;
                lkb -= 2 * lka;
                lkb = max(lkb, 0ll);
                res += (lkb + 1) / 2;
            } else {
                res += (lkb + lka + 2) / 3;
            }
        } else {
            if (lkb == 0) {
                res += lkc;
                lka -= 2 * lkc;
                lka = max(lka, 0ll);
                res += (lka + 2) / 3;
            } else {
                res += lkc;
                lkb -= lkc;
                lkb = max(lkb, 0ll);
                res += (lkb + 1) / 2;
            }
        }
        ans = min(ans, res);
    }
    return ans;
}

int main() {
//    viv = true;
    /**
    multiset <ll, greater<ll>> ss = {1, 3, 4, 4, 5, 1};
    ss.erase(ss.find(4));
    auto z = ss.lower_bound(1);
    cout << *z << endl;
    z = ss.lower_bound(2);
    cout << *z << endl;
    z = ss.lower_bound(3);
    cout << *z << endl;
    z = ss.lower_bound(4);
    cout << *z << endl;
    z = ss.lower_bound(5);
    cout << *z << endl;
    z = ss.lower_bound(8);
    cout << *z << endl;
    z = ss.lower_bound(mod);
    cout << *z << endl;
    z = ss.lower_bound(inf);
    cout << *z << endl;
//    **/
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);


    for (i = 0; i < n; i++) {
        ll x;
        cin >> x;
        m.push_back(x);
        s.insert(x);
        if (x > a + b + c) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    ans += _triple();
    if (viv) {
        cout << ans << endl;
        cout << "Left ";
        for (auto i : s)
            cout << i << ' ';
        cout << endl;
    }
    ans += _double();
    if (viv) {
        cout << ans << endl;
        cout << "Left ";
        for (auto i : s)
            cout << i << ' ';
        cout << endl;
    }
    ans += _ones();
    cout << ans << endl;

    return 0;
}
/**
13
2 2 2
1 1 1 2 2 3 3 4 4 5 5 6 6

9
2 2 3
1 1 2 2 3 3 4 4 4

6
4 2 1
4 3 4 3 4 3

2
4 1 1
4 3

6
4 2 1
4 4 2 2 1 1


10
4 2 1
1 1 1 1 1 1 1 1 1 1

10
4 2 1
2 2 2 2 2 2 2 2 2 2

10
4 2 1
4 3 4 4 3 4 4 4 4 4

10
4 2 1
4 4 4 4 4 4 4 4 4 4

**/