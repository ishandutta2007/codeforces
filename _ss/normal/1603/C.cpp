#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10, mod = 998244353;
int a[N], n;

vector<pii> compress(vector<pii> vt)
{
    vector<pii> res;
    int cnt = 0;
    for (int i = 0; i < (int)vt.size() - 1; ++i)
    {
        cnt += vt[i].se;
        if (vt[i].fi != vt[i + 1].fi)
        {
            res.eb(vt[i].fi, cnt);
            cnt = 0;
        }
    }
    res.eb(vt.back().fi, cnt + vt.back().se);
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<pii> prv = {mp(a[n], 1)}; // fi = val, se = cnt
        ll res = 0;
        for (int i = n - 1; i; --i)
        {
            vector<pii> nw;
            for (pii state : prv)
            {
                int v = state.fi, cnt = state.se;
                int k = (a[i] - 1) / v + 1;
                res = (res + (ll)(k - 1) * cnt * i) % mod;
                nw.eb(a[i] / k, cnt);
            }
            nw.eb(a[i], 1);
            prv = compress(nw);
        }
        cout << res << "\n";
    }
    return 0;
}