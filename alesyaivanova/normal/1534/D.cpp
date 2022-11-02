#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2007;
int d[maxn][maxn];
int n;
bool used[maxn];
set<pii> ed;

void ask(int v) {
    cout << "? " << v + 1 << endl;
    for (int i = 0; i < n; i++) {
        cin >> d[v][i];
        d[i][v] = d[v][i];
    }
}

void solve(int v, vector<int>& cur) {
    if (!used[v]) {
        used[v] = 1;
        ask(v);
    }
    int u = v;
    for (int to : cur) {
        if (d[v][to] == 1)
            ed.emplace(min(v, to), max(v, to));
        if (d[v][to] > d[v][u])
            u = to;
    }
    if (d[v][u] <= 1)
        return;
    if (!used[u]) {
        used[u] = 1;
        ask(u);
    }
    int len = d[v][u];
    vector<int> way(len + 1);
    for (int to : cur) {
        int d1 = d[v][to];
        int d2 = d[u][to];
        if (d1 + d2 == len) {
            way[d1] = to;
            used[to] = 1;
        }
    }
    for (int i = 0; i < len; i++) {
        ed.emplace(min(way[i], way[i + 1]), max(way[i], way[i + 1]));
    }
    vector<vector<int> > new_cur(len + 1);
    for (int to : cur) {
        int d1 = d[v][to];
        int d2 = d[u][to];
        int new_len = (d1 + d2 - len) / 2;
        int i = d1 - new_len;
        new_cur[i].pb(to);
        d[way[i]][to] = new_len;
        d[to][way[i]] = new_len;
    }
    for (int i = 0; i <= len; i++) {
        solve(way[i], new_cur[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> cur(n);
    for (int i = 0; i < n; i++)
        cur[i] = i;
    solve(0, cur);
    cout << "!\n";
    for (pii u : ed) {
        cout << u.ff + 1 << " " << u.ss + 1 << "\n";
    }
    cout << endl;
}