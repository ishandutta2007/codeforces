#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r2", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 200200;

ll h[MAXN];
ll down[MAXN];

vector<int> g[MAXN];
vector<pair<ll, int>> arr[MAXN];
ll maxx = 0;
ll curr = 0;
ll best = 0;

ll dfs(int v, int p = -1) {
    ll x = 0;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        ll y = dfs(u, v);
        x = max(x, y);
        arr[v].push_back({y, u});
    }
    curr += max(0ll, h[v] - x);
    return down[v] = max(x, h[v]);
}

void dfs_up(int v, int p = -1, ll y = 0) {
    if (p != -1) {
        arr[v].push_back({y, p});
    }
    sort(all(arr[v]), greater<pii>());
    vector<pair<ll, int>> vals;
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        vals.push_back({down[u], u});
    }
    sort(all(vals), greater<pii>());
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        ll cur_y = max(y, h[v]);
        if (sz(vals) == 0) {

        } else if (vals[0].second != u) {
            cur_y = max(cur_y, vals[0].first);
        } else if (sz(vals) == 1) {

        } else {
            cur_y = max(cur_y, vals[1].first);

        }
        dfs_up(u, v, cur_y);
    }
}

ll get(int v, int u) {
    ll x = 0;
    if (sz(arr[v]) == 0) {
        x = 0;
    }  else if (arr[v][0].second != u) {
        x = arr[v][0].first;
    }  else if (sz(arr[v]) == 1) {
        x = 0;
    } else {
        x = arr[v][1].first;
    }
    return max(0ll, h[v] - x);
}

void rotate(int v, int p = -1) {
    best = min(best, curr);

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }   
        ll prev_curr = curr;
        curr -= get(v, -1);
        curr += get(v, u);
        curr += get(u, -1);
        curr -= get(u, v);
        rotate(u, v);
        curr = prev_curr;
    }
}

void solve() { 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        maxx = max(maxx, h[i]);
    }
    curr = maxx;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    dfs_up(0);
    best = curr;
    rotate(0);


    cout << best << endl;

}