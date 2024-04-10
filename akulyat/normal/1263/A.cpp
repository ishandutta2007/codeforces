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
    n = 3;
    m.clear();
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());
    if (m[2] >= m[1] + m[0]) {
        cout << m[0] + m[1] << '\n';
        return;
    }
    ll dif = m[1] + m[0] - m[2];
    ll ans = 0;
    dif /= 2;
    ans += dif;
    m[0] -= dif;
    m[1] -= dif;
    ans += min(m[0] + m[1], m[2]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}