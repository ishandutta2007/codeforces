#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
const long long mod = 998244353;
const long long mod2 = 1e9+7;
const long long inf = ml * ml * ml + 7;
const int pc = 123457;
const int pc2 = 110329;
const ld cons = 1.95004;
const ld eps = 1e-4;
 
ll n, k, ans, cc;
vector<vector<ll>> reb;
vector<ll> col, q, col2, p, col3;
vector<pll> all, all2;
set<ll> s;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    for (auto s : reb[v])
        if (col[s] == -1) 
            DFS(s, c + 1);
    q.push_back(v);
    all.push_back({col[v], v});
}

void DFS2(ll v, ll c) {
    col2[v] = c;
    for (auto s : reb[v])
        if (col2[s] == -1) {
            DFS2(s, c + 1);
            p[s] = v;
        }
    all2.push_back({col2[v], v});
}

void DFS3(ll v, ll c) {
    if (s.count(v))
        c = 0;
    col3[v] = c;
    ans = max(ans, c);
    if (ans == c)
        cc = v;
    for (auto s : reb[v])
        if (col3[s] == -1) 
            DFS3(s, c + 1);
}


void solve() {
    cin >> n;
    reb.resize(n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.resize(n, -1);
    col2.resize(n, -1);
    col3.resize(n, -1);
    DFS(0, 0);
    sort(all.rbegin(), all.rend());

    ll a = all[0].S;
    if (viv)
        cout << "I see a = " << a << endl;
    p.resize(n);
    p[a] = a;
    DFS2(a, 0);
    if (viv) {
        cout << "Par: ";
        for (auto i : p)
            cout << i << ' ';
        cout << endl;
    }
    sort(all2.rbegin(), all2.rend());
    ll b = all2[0].S;
    if (viv)
        cout << "I see b = " << b << " on " << all2[0].F << endl;

    ll rb = b;
    vector<ll> pr;
    for (ll i = 0; i < all2[0].F + 1; i++) {
        pr.push_back(b);
        if (viv)
            cout << "from " << b;
        b = p[b];
        if (viv)
            cout << " to " << b << '\n';
    }
    b = rb;

    for (auto i: pr)
        s.insert(i);

    if (viv) {
        cout << "A to b: ";
        for (auto i : s)
            cout << i << ' ';
        cout << endl;        
    }
    DFS3(a, 0);
    if (viv)
        cout << "I see c = " << cc << endl;

    ll rcc = cc;
    while (!s.count(cc)) {
        p.push_back(cc);
        s.insert(cc);
        cc = p[cc];
    }
    cc = rcc;

    if (cc == a || cc == b)
        cc = 0;
    while (cc == a || cc == b)
        cc++;

    if (viv)
        cout << all2[0].F << ' ' <<  ans << '\n';
    cout << all2[0].F + ans << '\n';
    cout << a + 1 << ' ' << b + 1 << ' ' << cc + 1 << '\n';
}


int main() {
//  viv = true;
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}