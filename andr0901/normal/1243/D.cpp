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

vector <set <int>> gr;
vector <int> colors;
int cur;
set <int> not_used;

void dfs(int v) {
    //cout << v + 1 << " " << cur << "\n";
    vector <int> to_dfs;
    not_used.erase(v);
    for (int u : not_used)
        if (gr[v].find(u) == gr[v].end())
            to_dfs.pb(u);
    for (int i : to_dfs) {
        not_used.erase(i);
        //cout << i + 1 << " ";
    }
    //cout << "\n";
    for (int i : to_dfs)
        dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, v--, u--;
        gr[v].insert(u), gr[u].insert(v);
    }
    forn (i, 0, n)
        not_used.insert(i);
    colors.resize(n);
    cur = 0;
    forn (i, 0, n)
        if (not_used.find(i) != not_used.end()) {
            dfs(i);
            cur++;
        }
    cout << cur - 1;
    return 0;
}