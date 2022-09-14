#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int P = 1e9 + 7;

void mul(int &a, int b) {
    a = ll(a) * b % P;
}
 
void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

const int MAXN = 500500;

int p[MAXN];
int t[MAXN];

int get(int v) {
    return p[v] = (p[v] == v ? v : get(p[v]));
}

bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v || (t[u] && t[v])) {
        return false;
    }
    p[u] = v;
    t[v] |= t[u];
    return true;
}

void solve() {  
    int n, m;
    cin >> n >> m;
    iota(p, p + m, 0);

    int cnt = 1;
    vector<int> res;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        if (k == 1) {
            int u;
            cin >> u;
            --u;

            u = get(u);
            if (!t[u]) {
                t[u] = 1;
                mul(cnt, 2);
                res.push_back(i);
            }
        } else {
            int u, v;
            cin >> u >> v;
            --u; --v;

            if (unite(u, v)) {
                mul(cnt, 2);
                res.push_back(i);   
            }
        }
    }

    cout << cnt << " " << sz(res) << endl;
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << endl;

    
}