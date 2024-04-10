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
    ll was = n;
    vector <ll> v;
    while (n) {
        v.push_back(n%3);
        n/=3;
    }
    v.push_back(0);

    ll las = -1;
    for (int i = 0; i < v.size(); i++)
        if (v[i] == 2)
            las = i;
    if (las == -1) {
        cout << was << '\n';
        return;
    }
    las++;
    while (v[las] == 1)
        las++;
    v[las] = 1;
    for (int i = 0; i < las; i++)
        v[i] = 0;
    ll ans = 0;
    reverse(v.begin(), v.end());
    for (auto i : v)
        ans *=3, ans += i;
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