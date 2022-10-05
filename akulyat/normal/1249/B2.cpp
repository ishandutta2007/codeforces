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
    m.clear();
    vector<ll> ans(n, -1);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a--;
        m.push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (ans[i] == -1) {
            ll res = 0;
            ll cur = i;
            ll want = i;
            vector <ll> all;
            all.push_back(cur);
            cur = m[i];
            while (cur != want)
                all.push_back(cur), cur = m[cur];
            for (auto k : all)
                ans[k] = all.size();
        }
    for (auto i : ans)
        cout << i << ' ';
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