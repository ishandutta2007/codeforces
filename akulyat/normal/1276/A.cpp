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
string s;
vector<bool> del;
vector<ll> v;


bool bad(ll pl) {
    string t;
    t += s[pl-2];
    t += s[pl-1];
    t += s[pl-0];
    if (del[pl] || del[pl-1] || del[pl-2])
        return false;
    if (t == "two")
        return true;
    if (t == "one")
        return true;
    return false;
}

void d(ll pl) {
    v.push_back(pl);
    del[pl] = true;
}

void solve() {
    cin >> s;
    n = s.size();
    del.clear();
    del.resize(n, false);
    v.clear();
    for (ll i = 2; i < n; i++) {
        if (bad(i)) {
            if (i < n-1 && s[i] != s[i+1])
                d(i);
            else
                d(i-1);
        }
    }
    cout << v.size() << '\n';
    for (auto i : v)
        cout << i+1 << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();



    return 0;
}