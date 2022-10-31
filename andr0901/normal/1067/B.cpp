#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
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
    int n, k;
    cin >> n >> k;
    vector <vector <int>> gr(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    deque <int> a;
    vector <int> used(n);
    forn (i, 0, n) 
        if (sz(gr[i]) == 1)
            a.pb(i), used[i] = 1;
    while (!a.empty()) {
        int v = a.front();
        a.pop_front();
        //cout << v << ": " << used[v] << " " << sz(gr[v]) << "\n";
        for (auto u : gr[v]) {
            if (!used[u]) {
                used[u] = used[v] + 1;
                a.pb(u);
            }
            if (used[u] != used[v] + 1 && used[u] != used[v] - 1)
                return cout << "No", 0;
        }
        if (used[v] == k + 1 && sz(gr[v]) < 3) 
            return cout << "No", 0;
        if (1 < used[v] && used[v] < k + 1 && sz(gr[v]) <= 3)
            return cout << "No", 0;
    }
    int cnt = 0;
    forn (i, 0, n) {
        if (used[i] > k + 1) 
            return cout << "No", 0;
        if (used[i] == k + 1)
            cnt++;
    }
    if (cnt != 1)
        cout << "No";
    else 
        cout << "Yes";
    return 0;
}