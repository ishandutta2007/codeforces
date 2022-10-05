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


ll n, m, d;
vector<ll> v;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    v.resize(m);
    for (auto &i : v)
        cin >> i;
    vector<ll> sum;
    sum.resize(m);
    sum[m-1] = v[m-1];
    for (ll i = m-2; i >= 0; i--)
        sum[i] = sum[i+1] + v[i];

    ll lpl = -1;
    vector<ll> ans(n, -1);
    for (ll i = 0; i < m; i++) {
        ll npl = lpl + d;
        npl = min(npl, n - sum[i]);
        for (ll j = npl; j < npl + v[i]; j++)
            ans[j] = i;
        lpl = npl + v[i] - 1;
    }
    for (auto &i : ans)
        i++;
    bool can = false;
    for (ll i = n - 1; i >= n - d && i >= 0; i--)
        if (ans[i])
            can = true;
    if (!can) {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    for (auto i : ans)
        cout << i << ' ';


    return 0;
}