#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 3e5 + 5;

int pr[maxn], h[maxn], c[maxn];
vector<pair<int, int>> g[maxn];

int f(int v) {
    if (pr[v] == v) {
        return pr[v];
    }
    return pr[v] = f(pr[v]);
}

void unite(int a, int b) {
    a = f(a);
    b = f(b);
    if (h[a] > h[b]) {
        pr[b] = a, c[a] += c[b];
        for (auto x: g[b]) {
            g[a].pb(x);
        }
    } else if (h[a] < h[b]) {
        pr[a] = b, c[b] += c[a];
        for (auto x: g[a]) {
            g[b].pb(x);
        }
    } else {
        pr[b] = a, c[a] += c[b], h[a]++;
        for (auto x: g[b]) {
            g[a].pb(x);
        }
    }
}

void solve() {
   int n, m, x;
   cin >> n >> m >> x;
   set<pair<int, int>> s;
   vector<int> ans;
   for (int i = 0; i < n; ++i) {
       pr[i] = i;
       h[i] = 1;
       cin >> c[i];
       s.insert({c[i], i});
   }
   for (int i = 0; i < m; ++i) {
       int a, b;
       cin >> a >> b;
       g[a - 1].pb({b - 1, i});
       g[b - 1].pb({a - 1, i});
   }
   while (s.size() > 1) {
       int v = s.rbegin()->s;
       s.erase({c[v], v});
       while (g[v].size() > 0) {
           if (v == f(g[v].back().f)) {
               g[v].pop_back();
           } else {
               if (c[v] + c[f(g[v].back().f)] < x) {
                   cout << "NO";
                   return;
               }
               ans.pb(g[v].back().s);
               s.erase({c[f(g[v].back().f)], f(g[v].back().f)});
               unite(v, g[v].back().f);
               c[f(v)] -= x;
               s.insert({c[f(v)], f(v)});
               break;
           }
       }
       if (g[v].size() == 0) {
           cout << "NO";
           return;
       }
   }
   cout << "YES\n";
   for (auto i: ans) {
       cout << i + 1 << '\n';
   }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}