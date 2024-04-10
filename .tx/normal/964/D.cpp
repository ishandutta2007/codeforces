#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

vector<int> g[222222];
bool del[222222];
int deg[222222];
int h[222222];

void dfs(int v, int p, int ch) {
    h[v] = ch;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v, ch + 1);
    }
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        int x;
        cin >> x;
        --x;
        if (x != -1) {
            g[i].push_back(x);
            g[x].push_back(i);
            deg[i]++;
            deg[x]++;
        }
    }

    int rt = -1;
    rep(i, 0, n) {
        if (deg[i] % 2 == 0) {
            rt = i;
            break;
        }
    }
    if (rt == -1) {
        cout << "NO";
        return;
    }
    dfs(rt, -1, 0);

    set<pair<int, int>> s;
    rep(i, 0, n) {
        if (deg[i] % 2 == 0) {
            s.insert({h[i], i});
        }
    }

    vector<int> ans;
    rep(it, 0, n) {
        if (s.empty()) {
            cout << "NO";
            return;
        }
        auto p = *s.rbegin();
        s.erase(p);
        int v = p.second;
        ans.push_back(v);
        del[v] = true;
        for (int i : g[v]) {
            if (!del[i]) {
                if (deg[i] % 2 == 0) {
                    s.erase({h[i], i});
                }
                deg[i]--;
                if (deg[i] % 2 == 0) {
                    s.insert({h[i], i});
                }
            }
        }
    }

    cout << "YES\n";
    for (int i : ans) {
        cout << i + 1 << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//kckejn