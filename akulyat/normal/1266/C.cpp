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


ll n, m;
bool viv = false;
vector<vector<ll>> v;

void solve() {
    cin >> n >> m;
    if (min(n, m) >= 2) {
        v.resize(n);
        for (auto &l : v)
            l.resize(m, 1);
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                v[i][j] *= (i + 1);
                v[i][j] *= (n + j + 1);
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++)
                cout << v[i][j] << ' ';
            cout << '\n';
        }
        return;
    }
    if (max(n, m) <= 1) {
        cout << 0 << endl;
        return;
    }
    ll cnt = 2;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cout << cnt << ' ', cnt++;
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while (t--)
    	solve();

    return 0;
}