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
    vector <ll> v(n);
    for (auto &i : v)
        cin >> i, i--;
    ll have = n - 1;
    ll maxi = -1;
    vector<bool> used(n, false);
    for (ll j = 0; j < n; j++)
        for (ll i = n-1; i > 0; i--)
            if (v[i] < v[i-1] && !used[i])
                swap(v[i], v[i-1]), used[i] = true;
    for (auto i : v)
        cout << i + 1 << ' ';
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