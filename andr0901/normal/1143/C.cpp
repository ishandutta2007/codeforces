#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> a;
set <int> ans;

void dfs(int v, int p = -1) {
    int f = 0;
    for (auto u : gr[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        if (!a[u])
            f = 1;
    }
    if (!f && a[v])
        ans.insert(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    gr.resize(n), a.resize(n);
    int root;
    forn (i, 0, n) {
        int t, c;
        cin >> t >> c;
        t--;
        a[i] = c;
        if (t != -2)
            gr[t].pb(i);
        else
            root = i;
    }
    dfs(root);
    if (ans.empty())
        return cout << -1, 0;
    for (auto i : ans)
        cout << i + 1 << " ";
    return 0;
}