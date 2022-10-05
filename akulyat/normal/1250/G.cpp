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


ll n, i, j, m, k, r;
vector<vector<ll>> f;
vector<char> a;
bool viv = false;

void solve() {
    cin >> n >> m >> k;
    f.clear();
    r = 0;
    for (i = 0; i < n; i++) {
        f.push_back({});
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++) {
            f[i].push_back(s[j] == 'R');
            if (f[i][j] == 1)
                r++;
        }
    }
    ll now = 0;
    vector<vector<ll>> ans;
    ans.resize(n);
    for (auto &l : ans)
        l.resize(m);
    ll who = 0;
    ll will = r / k;
    vector<ll> want(k, will);
    r -= will * k;
    for (ll i = 0; i < r; i++) {
        want[i]++;
    }
    if (viv) {
        cout << "Wish\n";
        for (auto i : want)
            cout << i << ' ';
        cout << endl;
    }
    for (ll i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            for (ll j = 0; j <= m-1; j++) {
                now += f[i][j];
                ans[i][j] = min(who, k-1);
                if (now == want[who])
                    who++, now = 0;
            }
        } else {
            for (ll j = m-1; j >= 0; j--) {
                now += f[i][j];
                ans[i][j] = min(who, k-1);
                if (now == want[who])
                    who++, now = 0;
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << char(a[ans[i][j]]);
        }
        cout << endl;
    }
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < 10; i++)
        a.push_back('0' + i);
    for (ll i = 0; i < 26; i++)
        a.push_back('a' + i);
    for (ll i = 0; i < 26; i++)
        a.push_back('A' + i);
    while (t--)
        solve();




    return 0;
}