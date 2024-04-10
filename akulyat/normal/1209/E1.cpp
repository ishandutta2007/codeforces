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

ll power(ll k, ll st) {
    ll res = 1;
    while (st--)
        res *= k;
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> f(n, vector<ll>(m, 0));
    for (auto& l : f)
        for (auto& e : l)
            cin >> e;
    vector<ll> v(m);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            v[j] = max(v[j], f[i][j]);

    vector <pll> tos;
    for (ll i = 0; i < m; i++)
        tos.push_back({-v[i], i});
    sort(tos.begin(), tos.end());
    vector <ll> ind;
    for (ll i = 0; i < min(n, m); i++)
        ind.push_back(tos[i].S);
    if (viv) {
        cout << "Cols: ";
        for (auto i : ind)
            cout << i << ' ';
        cout << endl;
    }

    ll k = min(n, m);

    ll ans = 0;
    for (ll i = 0; i < power(n, k); i++) {
        vector <ll> sh;
        ll x = i;
        for (ll i = 0; i < k; i++)
            sh.push_back(x % n), x /= n;

        vector <ll> res(n, 0);
        for (auto id : ind)
            {
            for (ll i = 0; i < n; i++)
                res[i] = max(res[i], f[(i+sh.back())%n][id]);
            sh.pop_back();
            }
        ll lans = 0;
        for (auto i : res)
            lans += i;
        ans = max(ans, lans);
        }
    cout << ans << endl;
}

int main()
{
//viv = true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin >> t;
while (t--)
    solve();

    return 0;
}