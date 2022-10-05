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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> fr(10, inf);
    vector<ll> las(10, -1);
    vector<vector<ll>> f(10);
    for(ll i = 0; i < n; i ++)
        f[s[i] - '0'].push_back(i);
    for (ll j = 0; j < 10; j++)
        if (f[j].size()) {
            las[j] = f[j].back();
            fr[j] = f[j][0];
        }

    for (ll i = 0; i < 10; i++) {
        bool bad = false;
        for (ll j = 0; j < i-1; j++)
            for (ll u = j + 1; u < i; u++)
                if (fr[u] < las[j])
                    bad = true;
        for (ll j = i+1; j < 10; j++)
            for (ll u = j + 1; u < 10; u++)
                if (fr[u] < las[j])
                    bad = true;
        if (!bad) {
            ll to = -1, from = inf;
            for (ll j = 0; j <= i-1; j++)
                if (las[j] != -1)
                    to = max(to, las[j]);
            for (ll j = i+1; j < 10; j++)
                if (fr[j] != inf)
                    from = min(from, fr[j]);

            auto k = lower_bound(f[i].begin(), f[i].end(), from);
            if (k != f[i].end() && (*k) <= to)
                bad = true;
            if (!bad) {
                if (viv)
                    cout << "Ok without " << i << ' ' << from << ' ' << to << endl;
                string ans;
                for (ll pl = 0; pl < n; pl++) {
                    if (s[pl] - '0' < i)
                        ans += '1';
                    if (s[pl] - '0' > i)
                        ans += '2';
                    if (s[pl] - '0' == i) {
                        if (pl > to)
                            ans += '1';
                        else
                            ans += '2';
                    }
                }
            cout << ans << '\n';
            return;
            }
        }
    }
    cout << '-' << '\n';
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