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

vector <set <int>> gr;
vector <int> path;

void dfs(int v, int p = -1) {
    path.pb(v);
    for (int u : gr[v])
        if (u != p)
            dfs(u, v);
}

void solve() {
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << "YES\n";
        forn (i, 0, 26)
            cout << (char)(i + 'a');
        cout << "\n";
        return;
    }
    forn (i, 0, sz(s))
        s[i] -= 'a';
    gr = vector <set <int>> (26);
    forn (i, 1, sz(s)) {
        gr[s[i]].insert(s[i - 1]);
        gr[s[i - 1]].insert(s[i]);
    }
    int cnt = 0, v = -1;
    forn (i, 0, 26) {
        if (gr[i].size() > 2) {
            cout << "NO\n";
            return;
        }
        if (gr[i].size() == 1) {
            cnt++;
            v = i;
        }
    }
    if (cnt == 0) {
        cout << "NO\n";
        return;
    }
    path = vector <int>();
    dfs(v);
    int cur = -1;
    forn (i, 0, sz(path)) {
        if (path[i] == s[0]) {
            cur = i;
            break;
        }
    }
    if (cur == -1) {
        cout << "NO\n";
        return;
    }
    forn (i, 1, sz(s)) {
        if (cur + 1 < path.size() && path[cur + 1] == s[i]) {
            cur++;
            continue;
        }
        if (cur - 1 >= 0 && path[cur - 1] == s[i]) {
            cur--;
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector <bool> used(26);
    for (int i : path) {
        used[i] = true;
        cout << (char)(i + 'a');
    }
    forn (i, 0, 26) {
        if (!used[i]) {
            cout << (char)(i + 'a');
        }
    }
    cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}