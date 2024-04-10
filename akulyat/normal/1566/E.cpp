#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
vector<vector<int>> e;
bool viv = false;

vector<int> d;
vector<bool> lf, p;
int ans = 0;
int lc, pc;

void DFS(int v, int c = 0) {
    d[v] = c;
    int k = 0, lk = 0;
    lf[v] = true;
    for (auto u : e[v])
        if (d[u] == -1) {
            DFS(u, c + 1);
            if (!p[u]) {
                lf[v] = false;
                k++;
                lk += lf[u];
            }
        }

    // cout << v << ": " << k << ' ' << lk << endl;
    if (k == lk && !lf[v]) {
        if (v)  
            p[v] = true;
        ans = max(ans, k);
    }
    lc += lf[v];
    pc += p[v];
}

void solve() {
    cin >> n;
    e.assign(n, {});
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }    
    d.assign(n, -1);
    lf.assign(n, false);
    p.assign(n, false);
    ans = 0;
    lc = pc = 0;
    DFS(0);
    ans = lc - pc;
    cout << ans << '\n';
    // cout << ' ' << lc << ' ' << pc << endl;
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin >> t;
    while (t--)
        solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}