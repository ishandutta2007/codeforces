#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1005;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vv <bool> vis(n, m, false);
    const int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    vv <int> label(n, m, -1);
    int cur = 0;
    vector <pii> pos;
    function <void(int, int)> dfs = [&](int x, int y) {
        vis[x][y] = true, label[x][y] = cur, pos.eb(x, y);
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!vis[nx][ny] && s[nx][ny] == '*')
                dfs(nx, ny);
        }
    };
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '*' && !vis[i][j]) {
        dfs(i, j), cur++;
        if (pos.size() != 3) {
            cout << "NO\n";
            return;
        }
        if (pos[0].X == pos[1].X && pos[1].X == pos[2].X) {
            cout << "NO\n";
            return;
        }
        if (pos[0].Y == pos[1].Y && pos[1].Y == pos[2].Y) {
            cout << "NO\n";
            return;
        }
        pos.clear();
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '*') {
        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            if (label[ni][nj] != label[i][j] && s[ni][nj] == '*') {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}