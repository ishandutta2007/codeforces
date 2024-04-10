#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

vector <vector <pii>> gr;
vector <int> used, ans;

void dfs(int v) {
    used[v] = 1;
    for (auto u : gr[v]) {
        if (!used[u.fs])
            dfs(u.fs);
        if (used[u.fs] == 1) {
            //cout << v + 1 << " " << u.fs + 1 << "\n";
            ans[u.sc] = 1;
        }
    }
    used[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].eb(u, i);
    }
    used.resize(n), ans.resize(m);
    forn (i, 0, n) 
        if (!used[i])
            dfs(i);
    bool ok = 0;
    forn (i, 0, m) 
        if (ans[i]) 
            ok = 1;
    if (!ok)
        cout << "1\n";
    else 
        cout << "2\n";
    forn (i, 0, m) 
        cout << ans[i] + 1 << " ";
    return 0;
}