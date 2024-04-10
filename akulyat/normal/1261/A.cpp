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


ll n, i, j, k;
vector<ll> m;
bool viv = false;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    k--;
    vector<ll> pl;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '(')
            pl.push_back(i);
    }
    ll fr = 0;
    vector<ll> w;
    ll ost = n/2 - k;
    while (k--) {
        w.push_back(fr), fr+=2;
    }
    for (i = 0; i < ost; i++)
        w.push_back(fr + i);
    vector<pll> ans;
    for (ll i = 0; i < n/2; i++) {
        ll a = w[i];
        ll b = pl[i];
        if (a > b)
            swap(a, b);
        ans.push_back({a, b});
        if (a + 1 <= b - 1)
            ans.push_back({a + 1, b - 1});
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.F + 1 << ' ' << i.S + 1 << '\n';
}

void solve2() {
    cin >> n >> k;
    cin >> s;
    k--;
    ll ost = n/2 - k;
    string ws;
    for (ll i = 0; i < k; i++)
        ws += "()";
    for (ll i = 0; i < ost; i++)
        ws += '(';
    for (ll i = 0; i < ost; i++)
        ws += ')';

    vector<ll> o, c;
    ll op, cp;
    op = cp = 0;
    vector<pll> ans;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (s[j] != ws[i])
            j++;
        ans.push_back({i, j});
        reverse(s.begin() + i, s.begin() + j + 1);
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.F + 1 << ' ' << i.S + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve2();

    return 0;
}