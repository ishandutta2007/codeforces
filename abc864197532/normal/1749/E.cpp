#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int mod = 998244353, N = 1 << 18, D = 22;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    vv <int> dis(n, m, 1 << 30);
    vv <pii> rt(n, m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) if (s[i][j] == '#') {
            if (i) dis[i - 1][j] = -1;
            if (j) dis[i][j - 1] = -1;
            if (i + 1 < n) dis[i + 1][j] = -1;
            if (j + 1 < m) dis[i][j + 1] = -1;
        }
    }
    priority_queue <array <int, 3>, vector <array <int, 3>>, greater <array <int, 3>>> pq;
    for (int i = 0; i < n; ++i) if (dis[i][0] != -1) {
        dis[i][0] = s[i][0] != '#';
        pq.push({dis[i][0], i, 0});
    }
    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (d != dis[r][c]) continue;
        for (int dx : {-1, 1}) for (int dy : {-1, 1}) {
            if (0 <= dx + r && dx + r < n && 0 <= dy + c && dy + c < m) {
                if (dis[dx + r][dy + c] > dis[r][c] + (s[dx + r][dy + c] != '#')) {
                    dis[dx + r][dy + c] = dis[r][c] + (s[dx + r][dy + c] != '#');
                    pq.push({dis[dx + r][dy + c], dx + r, dy + c});
                    rt[dx + r][dy + c] = {r, c};
                }
            }
        }
    }
    array <int, 3> mn = {1 << 30, 0, 0};
    for (int i = 0; i < n; ++i) if (dis[i][m - 1] != -1)
        mn = min(mn, {dis[i][m - 1], i, m - 1});
    if (mn[0] == 1 << 30) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int r = mn[1], c = mn[2];
        while (c) {
            s[r][c] = '#';
            tie(r, c) = rt[r][c];
        }
        s[r][c] = '#';
        for (int i = 0; i < n; ++i)
            cout << s[i] << '\n';
    }
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}