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


ll n, i, j, m;
vector<ll> col, q, col2, ans;
vector<bool> used;
vector<vector<ll>> reb, rreb;
bool viv = false;

void DFS(ll v) {
    col[v] = 1;
    for (auto s : reb[v])
        if (col[s] == -1)
            DFS(s);
    q.push_back(v);
}

void DFS2(ll v, ll c) {
    if (viv)
        cout << "Let's go " << v << ' ' << c << endl;
    col2[v] = c;
    for (auto s : rreb[v])
        if (col2[s] == -1) {
            DFS2(s, c);
        }
}

void DFS3(ll v) {
    used[v] = true;
    ans.push_back(v);
    for (auto s : reb[v])
        if (!used[s])
            DFS3(s);
}

void solve() {
    cin >> n >> m;
    reb.clear();
    reb.resize(n);
    rreb.clear();
    rreb.resize(n);
    q.clear();

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if (a != b)
            reb[a].push_back(b);
        if (a != b)
            rreb[b].push_back(a);
    }
    col.clear();
    col.resize(n, -1);
    for (ll i = 0; i < n; i++)
        if (col[i] == -1)
            DFS(i);
    reverse(q.begin(), q.end());

    col2.clear();
    col2.resize(n, -1);
    ll tc = 0;
    for (auto i : q)
        if (col2[i] == -1)
            DFS2(i, tc), tc++;

    if (viv) {
        cout << "\\ ";
        for (auto i : col2)
            cout << i << ' ';
        cout << endl;
    }
    if (tc == 1) {
        cout << "No\n";
        return;
    }

    vector<ll> out(tc, false);
    for (ll i = 0; i < n; i++)
        for (auto s : reb[i])
            if (col2[s] != col2[i])
                out[col2[i]] = true;

    ll good = -1;
    for (ll i = 0; i < tc; i++)
        if (!out[i])
            good = i;

    ll v = -1;
    for (ll i = 0; i < n; i++)
        if (col2[i] == good)
            v = i;

    if (viv)
        cout << "good is " << v << endl;

    ans.clear();
    used.clear();
    used.resize(n, false);
    DFS3(v);

    cout << "Yes\n";
    cout << ans.size() << ' ' << n - ans.size() << '\n';
    for (auto i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
    for (ll i = 0; i < n; i++)
        if (!used[i])
            cout << i + 1 << ' ';
    cout << '\n';
}



int main() {
    //viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();



    return 0;
}