#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

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


const int MAXN = 200200;

int to[MAXN * 35][2];

int m = 1;
void add(int v, int x, int k) {
    if (k == -1) {
        return;
    }
    
    int bit = (x >> k) & 1;
    
    if (to[v][bit] == -1) {
        to[m][0] = to[m][1] = -1;
        to[v][bit] = m++;
    }

    add(to[v][bit], x, k - 1);
}

int dfs(int v) {
    int res = 0;
    for (int i = 0; i < 2; ++i) {
        if (to[v][i] != -1) {
            res = max(res, dfs(to[v][i]));
        }
    }
    res += (to[v][0] != -1 && to[v][1] != -1);
    return res;
}

void solve() { 
    to[0][0] = to[0][1] = -1;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(0, x, 30);
    }
    cout << n - 1 - dfs(0) << endl;
}