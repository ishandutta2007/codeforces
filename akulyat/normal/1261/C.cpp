#include <bits/stdc++.h>

#pragma GCC optimize("Ofast", "unroll-all-loops")
#pragma GCC target("avx2")

using namespace std;

#define F first
#define S second
typedef int   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, m;
vector<vector<bool>> f, z, ans;
vector<ll> r;
vector<vector<ll>> reb;
vector<ll> used;
vector<ll> col;
bool viv = false;

inline void make_edges() {
    reb.resize(n * m);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m - 1; j++) {
            ll a = i * m + j;
            ll b = i * m + j + 1;
            reb[a].push_back(b);
            reb[b].push_back(a);
        }
    }
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < m; j++) {
            ll a = i * m + j;
            ll b = i * m + m + j;
            reb[a].push_back(b);
            reb[b].push_back(a);
        }
    }
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < m - 1; j++) {
            ll a = i * m + j;
            ll b = i * m + m + j + 1;
            reb[a].push_back(b);
            reb[b].push_back(a);
        }
    }
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 1; j < m; j++) {
            ll a = i * m + j;
            ll b = i * m + m + j - 1;
            reb[a].push_back(b);
            reb[b].push_back(a);
        }
    }
}

inline void BFS0() {
    vector<ll> st;
    r.resize(n * m, -1);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++) {
            if (f[i][j] == false) {
                st.push_back(i * m + j);
                r[st.back()] = 0;
            }
        }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++) {
            if (f[i][j] == true && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                st.push_back(i * m + j);
                r[st.back()] = 1;
            }
        }
    ll who = 0;
    while (who != st.size()) {
        ll v = st[who];
        for (auto s : reb[v])
            if (r[s] == -1) {
                r[s] = r[v] + 1;
                st.push_back(s);
            }
        who++;
    }
    if (viv)
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++)
                cout << r[i*m+j] << ' ';
            cout << endl;
        }
}

inline void BFS1(ll k) {
    vector<ll> st;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (z[i][j])
                st.push_back(i * m + j);

    for (auto &i : col)
        i = -1;
    for (auto i : st)
        col[i] = 0;
    ll who = 0;
    while(who != st.size()) {
        ll v = st[who];
        for (auto s : reb[v]) {
            if (col[s] == -1) {
                col[s] = col[v] + 1;
                st.push_back(s);
            }
        }
        who++;
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            if (col[i*m + j] <= k && col[i*m+j] != -1)
                ans[i][j] = true;
            else
                ans[i][j] = false;
}

inline bool solve(ll k, bool show = false) {
    for (auto &i : used)
        i = -1;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            if (r[i * m + j] > k)
                z[i][j] = true;
            else
                z[i][j] = false;
    }
    for (auto &i : used)
        i = -1;
    BFS1(k);
    if (show || viv) {
        if (viv) {
            cout << k << endl;
            cout << "Fire start" << endl;
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (z[i][j])
                    cout << 'X';
                else
                    cout << '.';
            }
            cout << '\n';
        }
        if (viv) {
            cout << "Fire end" << endl;
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    if (ans[i][j])
                        cout << 'X';
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
        if (viv) {
            cout << "How long wait" << endl;
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    cout << col[i*m+j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            if (ans[i][j] != f[i][j] || ((i == 0 || i == n-1 || j == 0 || j == m-1) && f[i][j] && col[i*m+j] < k))
                return false;
    }
    return true;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        string s;
        cin >> s;
        f.push_back({});
        z.push_back({});
        ans.push_back({});
        for (ll j = 0; j < m; j++) {
            f.back().push_back(s[j] == 'X');
            z.back().push_back(s[j] == 'X');
            ans.back().push_back(s[j] == 'X');
        }
    }

    ll l = 0;
    ll r = min(n, m) + 1;
    used.resize(n * m, -1);
    col.resize(n * m, -1);
    make_edges();
    BFS0();
    while (l + 1 < r) {
        ll mi = l + r >> 1;
        if (solve(mi))
            l = mi;
        else
            r = mi;
    }
    cout << l << endl;
    solve(l, true);





    return 0;
}