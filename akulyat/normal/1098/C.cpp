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
const long long gs = 500 * kk;

ll n, i, j, s;
vector<ll> reb[gs + 10];
vector<ll> col, tc;
bool viv = false;


bool can(ll r) {
    vector<ll> c;
    c.push_back(1);
    ll ost = n - 1;
    ll can = 1;
    while (ost) {
        can *= r;
        ll add = min(ost, can);
        ost -= add;
        c.push_back(add);
    }
    ll mini = 0;
    for (ll i = 0; i < c.size(); i++)
        mini += c[i] * (i + 1);
    if (mini > s)
        return false;
    return true;
}

void work(ll r) {
    if (r == 1) {
        cout << "Yes" << endl;
        for (ll i = 1; i < n; i++)
            cout << i << ' ';
        exit(0);
    }
    ll lans = n * (n + 1) / 2;
    vector<ll> p(n, -1);
    vector<ll> c, on;
    {
        c.push_back(1);
        ll ost = n - 1;
        ll can = 1;
        while (ost) {
            can *= r;
            ll add = min(ost, can);
            ost -= add;
            c.push_back(add);
        }
        while (c.size() < n)
            c.push_back(c.back());
        for (ll i = 0; i < n; i++)
            on.push_back(1);
    }
    for (auto &i : c)
        i--;
    ll ost = lans - s;
    for (ll i = n - 1; i >= 0; i--) {
        ll lev = i;
        c[lev]++;
        on[lev]--;
        ll can = 0;
        while (!c[can])
            can++;
        ll dif = lev - can;
        dif = min(dif, ost);
        ost -= dif;
        lev -= dif;
        if (viv)
            cout << "ver " << i << " is going to " << lev << endl;
        c[lev]--;
        on[lev]++;
    }
    ll now = 0;
    vector<vector<ll>> im;
    if (viv) {
        cout << "Levels are: ";
        for (auto i : on)
            cout << i << ' ';
        cout << endl;
    }

    for (ll i = 0; i < n; i++) {
        im.push_back({});
        for (ll j = 0; j < on[i]; j++) {
            im.back().push_back(now);
            now++;
        }
        if (i) {
            for (ll j = 0; j < on[i]; j++) {
                if (viv)
                    cout << "for " << im[i][j] << " f is " << im[i-1][j/r] << endl;
                p[im[i][j]] = im[i - 1][j / r];
            }
        }
    }
    cout << "Yes\n";
    for (ll i = 1; i < n; i++)
        cout << p[i] + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    if (n * (n + 1) / 2  < s) {
        cout << "No" << endl;
        exit(0);
    }

    ll l = 0;
    ll r = n;

    while (l + 1 < r) {
        ll m = l + r >> 1;
        if (can(m))
            r = m;
        else
            l = m;
    }
    if (viv)
        cout << "Answer is" <<  r << endl;

    if (r == n) {
        cout << "No";
        exit(0);
    }

    work(r);





    return 0;
}
/**
100000 5000050000
100000 5000049999
100000 5000050001






**/