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
string s, t;
bool viv = false;

ll prt(vector<ll> v) {
    ll n = v.size();
    vector<bool> used(n, false);
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
        if (!used[i]) {
            vector <ll> p;
            p.push_back(i);
            ll now = v[i];
            while (now != i)
                p.push_back(now), now = v[now];
            for (auto j : p)
                used[j] = true;
            cnt++;
        }
    if (viv) {
        cout << "_________" << '\n';
        cout << cnt << '\n';
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    }

    return cnt & 1;
}

void solve() {
    vector<ll> bl(26, 0);
    cin >> n;
    cin >> s >> t;
    set<char> st;
    for (auto i : s)
        bl[i - 'a']++, st.insert(i);
    for (auto i : t)
        bl[i - 'a']--;
    for (auto i : bl)
        if (i) {
            cout << "NO\n";
            return;
        }
    if (st.size() != n) {
        cout << "YES\n";
        return;
    }
    vector<pair<char, ll>> a, b;
    for (ll i = 0; i < n; i++)
        a.push_back({s[i], i});
    for (ll i = 0; i < n; i++)
        b.push_back({t[i], i});
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> va, vb;
    for (auto i : a)
        va.push_back(i.S);
    for (auto i : b)
        vb.push_back(i.S);
    if (prt(va) != prt(vb))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}