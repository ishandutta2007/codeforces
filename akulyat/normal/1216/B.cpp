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
vector<pll> m;
bool viv = false;

ll solve(vector<pll> m) {
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        res += i * m[i].F + 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (i = 0; i < n; i++)
        {
        ll a;
        cin >> a;
        m.push_back({a, i});
        }
    sort(m.begin(), m.end());
    ll ans1 = solve(m);
    reverse(m.begin(), m.end());
    ll ans2 = solve(m);

    if (ans1 < ans2)
        ans2 = ans1, reverse(m.begin(), m.end());

    cout << ans2 << endl;
    for (auto p : m)
        cout << p.S+1 << ' ';



    return 0;
}