#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("fma")
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

void solve() {
    cin >> n;
    m.clear();
    m.resize(n);
    for (auto &i : m)
        cin >> i;
    unordered_set<ll> s;
    for (auto i : m)
        s.insert(i);
    if (s.size() == m.size()) {
        cout << -1 << '\n';
        return;
    }
    ll l = 1;
    ll r = n;
    while (l + 1 < r) {
        ll mi = l + r >> 1;
        unordered_map<int, int> cnt;
        ll res = 0;
        bool good = false;
        for (ll i = 0; i < mi; i++) {
            cnt[m[i]]++;
            if (cnt[m[i]] == 1)
                res++;
        }
        if (res != mi)
            good = true;
        for (ll i = mi; i < n; i++) {
            cnt[m[i - mi]]--;
            if (cnt[m[i - mi]] == 0)
                res--;
            cnt[m[i]]++;
            if (cnt[m[i]] == 1)
                res++;
            if (res != mi)
                good = true;
        }
//        cout << "On " << l << ' ' << r << ' ' << good << endl;
        if (good)
            r = mi;
        else
            l = mi;
//        cout << "Get " << l << ' ' << r << endl;
    }
//    cout << "OK" << endl;
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
//    viv = true;
    while (t--)
        solve();

    return 0;
}