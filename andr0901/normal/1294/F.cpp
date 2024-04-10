#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;

pair <int, int> longest(int v, int p = -1) {
    pair <int, int> ans = {0, v};
    for (int u : gr[v]) {
        if (u == p)
            continue;
        auto cur = longest(u, v);
        cur.fs++;
        ans = max(ans, cur);
    }
    return ans;
}

vector <int> path;
bool found = false;

void make_path(int v, int fn, int p = -1) {
    if (found)
        return;
    if (v == fn) {
        found = true;
        return;
    }
    path.pb(v);
    for (int u : gr[v]) {
        if (p == u)
            continue;
        make_path(u, fn, v);
    }
    if (!found)
        path.pop_b();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].pb(u), gr[u].pb(v);
    }
    //cout << longest(0).fs << "\n";
    int v = longest(0).sc;
    int u = longest(v).sc;
    //cout << v << " " << u << "\n";
    make_path(v, u);
    path.pb(u);
    /*for (int i : path)
        cout << i << " ";
    cout << "\n";*/
    pii ans = {0, 0};
    if (path.size() == n) {
        forn (i, 0, n)
            if (i != v && i != u)
                return cout << n - 1 << "\n" << i + 1 << " " << u + 1 << " " << v + 1, 0;
    }
    forn (i, 0, sz(path) - 1) {
        for (int j : gr[path[i]]) {
            if (j != path[i - 1] && j != path[i + 1]) {
                //cout << j << " " << path[i] << " " << longest(j, path[i]).fs << " " << longest(j, path[i]).sc << "\n";
                ans = max(ans, longest(j, path[i]));
            }
        }
    }
    cout << ans.fs + path.size() << "\n";
    cout << v + 1 << " " << u + 1 << " " << ans.sc + 1;
    return 0;
}