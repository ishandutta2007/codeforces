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

void solve() {
    cin >> n;
    vector<ll> m, k;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        k.push_back(a);
        k[i] -= m[i];
    }

    while (k.size() && k.back() == 0)
        k.pop_back();
    reverse(k.begin(), k.end());
    while (k.size() && k.back() == 0)
        k.pop_back();

    while (k.size() > 1 && k[k.size() - 1] == k[k.size() - 2])
        k.pop_back();
    if (k.size() == 0) {
        cout << "YES\n";
        return;
    }
    if (k.size() == 1 && k[0] >= 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}