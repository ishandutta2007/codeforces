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


ll n, i, j;
vector<ll> m;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }

    ll s = n;
    ll st = 0;
    while (s > 1)
        s >>= 1, st++;

    ll kol = 1;
    ll j = 0;
    vector<vector<ll>> v;
    for (ll i = 0; i < st; i++) {
        ll lkol = kol;
        v.push_back({});
        while (lkol) {
            v.back().push_back(m[j]);
            lkol--;
            j++;
        }
        kol <<= 1;
    }
    v.push_back({});
    v.back().push_back(m.back());

    reverse(v.begin(), v.end());

    multiset<ll> ss;
    ll ans = 0;
    for (auto vec : v) {
        for (auto i : vec)
            ss.insert(i);
        if (viv) {
            for (auto i : ss)
                cout << i << ' ';
            cout << endl;
        }
        ll val = *ss.begin();
        if (val != -1) {
            ans += val;
            ss.erase(ss.begin());
        }
    }

    cout << ans;


    return 0;
}