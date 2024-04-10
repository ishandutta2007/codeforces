#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> gr(n), r_gr(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), r_gr[u].pb(v);
    }
    vector <bool> used(n);
    vector <int> to_consider;
    forn (v, 0, n) {
        if (!used[v]) {
            to_consider.pb(v);
            for (int u : gr[v])
                used[u] = 1;
        }
    }
    unordered_set <int> a;
    reverse(all(to_consider));
    for (int v : to_consider) {
        bool ok = 1;
        for (int u : r_gr[v]) 
            if (a.find(u) != a.end()) 
                ok = 0;
        if (ok)
            a.insert(v);
    }
    cout << sz(a) << "\n";
    for (int i : a)
        cout << i + 1 << " ";
    return 0;
}