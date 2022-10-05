#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3", "unroll-loops", "Ofast")
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
vector<vector<ll>> ans;
bool viv = false;

void solve() {
    vector<vector<bool>> dp;
    ll sum = 0;
    for (auto i : m)
        sum += i;
    dp.resize((m.size() + 1)/2 + 1);
    for (auto &vec : dp)
        vec.resize((sum + 1)/2 + 1);
   dp[0][0] = true;


    for (char i = 0; i < m.size(); i++)
        for (char kol = (int)dp.size() - 1; kol >= 1; kol--)
            for (int j = (int)dp[kol].size() - 1; j >= m[i]; j--)
                dp[kol][j] = dp[kol][j] | dp[kol-1][j-m[i]];
    vector <ll> p1;
    vector <ll> p2;
    ll a = m.size();
    ll c = m.size()/2;
    ll b = sum/2;
    while (!dp[c][b])
        b--;
    while (a) {
        a--;
        if (b - m[a] >=0 && c && dp[c-1][b-m[a]]) {
            b -= m[a];
            c--;
            p1.push_back(m[a]);
        } else
            p2.push_back(m[a]);
        if (viv)
            cout << "now " << a << ' ' << c << ' ' << b << endl;
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    if (viv) {
        for (auto i : p1)
            cout << i << ' ';
        cout << " : ";
        for (auto i : p2)
            cout << i << ' ';
        cout << endl;
    }

    for (ll i = 0; i < p1.size(); i++)
        ans[0][i+1] = p1[i];
    for (ll i = 0; i < p2.size(); i++)
        ans[1][(ll)p2.size() - 1 - i] = p2[i];
}



int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < 2*n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());
    reverse(m.begin(), m.end());
    ans.resize(2);
    ans[0].resize(n, -1);
    ans[1].resize(n, -1);
    ans[0][0] = m.back(), m.pop_back();
    ans[1][n-1] = m.back(), m.pop_back();
    reverse(m.begin(), m.end());

    solve();

    for (auto i : ans[0])
        cout << i << ' ';
    cout << endl;
    for (auto i : ans[1])
        cout << i << ' ';
    cout << endl;

    return 0;
}