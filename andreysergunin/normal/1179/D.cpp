#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);
   

const int MAXN = 500500;
const ll INF = 1e18;

vector<int> g[MAXN];

ll ans = 0;

ll dp[MAXN];
ll w[MAXN];

ll n;

struct Point {
    ll x, y;
};

bool operator<(const Point &a, const Point &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

ll dot(const Point &a, const Point &b) {
    return (ll)a.x * b.x + (ll)a.y * b.y;
} 

ll cross(const Point &a, const Point &b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

ll solve(vector<ll> f, vector<ll> g) {
    vector<Point> p;
    int m = sz(f);
    for (int i = 0; i < m; ++i) {
        p.push_back({f[i], g[i]});
    }

    // for (int i = 0; i < m; ++i) {
    //     cout << f[i] << " " << g[i] << endl;
    // }

    sort(all(p));

    vector<Point> st;

    ll res = n * (n - 1);

    for (int i = 0; i < m; ++i) {

        Point q = {1, 2 * p[i].y};
        Point r = {-q.y, q.x};

        int lf = 0, rg = sz(st);

        while (rg - lf > 1) {
            int mid = (lf + rg) / 2;

            Point s = st[mid + 1] - st[mid];

            if (cross(s, r) >= 0) {
                rg = mid;
            } else {
                lf = mid;
            }
        }

        if (lf < sz(st)) {
            res = min(res, n * (n - 1) + p[i].x + dot(st[lf], q));
        }
        if (rg < sz(st)) {
            res = min(res, n * (n - 1) + p[i].x + dot(st[rg], q));
        }

        while (sz(st) >= 2 && cross(st[sz(st) - 1] -  p[i], st[sz(st) - 2] - p[i]) <= 0) {
            st.pop_back();
        }
        st.push_back(p[i]);
    }

    return res;
}

void dfs(int v, int p = -1) {
    w[v] = 1;

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        w[v] += w[u];
    }

    dp[v] = w[v] * (w[v] - 1) / 2;

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        dp[v] = min(dp[v], (w[v] - w[u]) * (w[v] - w[u] - 1) / 2 + dp[u]);
    }

    vector<ll> fff = {0}, ggg = {0};

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }   
        ll ff = 2 * dp[u];
        ff += w[u] * w[u];
        ff -= 2 * w[u] * n;
        ff += w[u];
        ll gg = w[u];

        fff.push_back(ff);
        ggg.push_back(gg);
    }

    // cout << v << endl;
    ll x = solve(fff, ggg);
    ans = min(ans, x);
    // cout << x << endl;
    // cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = INF;
    
    dfs(0);

    // cout << ans << endl;

    ans /= 2;

    ans = 2ll * n * (n - 1) / 2 - ans;

    cout << ans << endl;

}