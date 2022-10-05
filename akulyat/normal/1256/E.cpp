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
vector<ll> dp, from;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back({a, i});
    }
    sort(m.begin(), m.end());
    dp.push_back(0);
    dp.push_back(inf);
    dp.push_back(inf);
    from.push_back(0);
    from.push_back(1);
    from.push_back(2);
    for (ll i = 3; i <= n; i++) {
        ll lans = inf;
        ll fr = -1;
        for (ll sz = 3; sz < 6; sz++)
            if (i - sz >= 0) {
                ll ws = lans;
                lans = min(lans, dp[i-sz] + m[i-1].F - m[i-sz].F);
                if (lans != ws)
                    fr = sz;
            }
        if (fr == -1) {
            while (true)
                cout << 'a' << endl;
        }
        dp.push_back(lans);
        from.push_back(fr);
    }
    cout << dp[n] << ' ';
    vector<ll> ans(n, -1);
    ll col = 0;
    ll now = n;
    while (now != 0) {
        ll dif = from[now];
        for (ll i = now - dif; i < now; i++)
            ans[i] = col;
        col++;
        now -= dif;
    }
    for (auto &i : ans)
        i++;

    vector<ll> rans(n, -1);
    for (ll i = 0; i < n; i++)
        rans[m[i].S] = ans[i];

    cout << col << endl;
    for (auto i : rans)
        cout << i << ' ';



    return 0;
}