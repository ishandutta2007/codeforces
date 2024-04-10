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


ll n, i, j, k;
vector<ll> m;
bool viv = false;

void solve() {
    cin >> n >> k;
    m.clear();
    m.resize(n);
    ll sum = 0;
    for (auto &i : m)
        cin >> i, sum += i;
    if (k < n || n == 2) {
        cout << "-1\n";
        return;
    }
    cout << 2 * sum << '\n';
    for (ll i = 0; i < n; i++) {
        ll a = i;
        ll b = i + 1;
        b %= n;
        a++, b++;
        cout << a << ' ' << b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}