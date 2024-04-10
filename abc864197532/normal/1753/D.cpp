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
const int mod = 998244353, N = 1 << 20, K = 250;

const int dx[8] = {0, 0, -2, 2, 1, -1, 1, -1}, dy[8] = {2, -2, 0, 0, 1, 1, -1, -1};
const int dx2[4] = {0, 0, 1, -1}, dy2[4] = {1, -1, 0, 0};
ll cost[8];
string need[8] = {"R", "L", "U", "D", "DR", "UR", "DL", "UL"};

void solve() {
    int n, m;
    cin >> n >> m;
    ll p, q;
    cin >> p >> q;
    for (int i = 0; i < 4; ++i)
        cost[i] = q, cost[i + 4] = p;
    vector <string> s(n);
    for (int i = 0; i < n; ++i) 
        cin >> s[i];
    vv <int> ccnum(n, m, -1);
    int tt = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (ccnum[i][j] == -1 && s[i][j] != '#') {
        queue <pii> q;
        q.emplace(i, j), ccnum[i][j] = tt++;
        while (!q.empty()) {
            int x, y; tie(x, y) = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx2[k], ny = y + dy2[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#' && ccnum[nx][ny] == -1) {
                    q.emplace(nx, ny), ccnum[nx][ny] = ccnum[x][y];
                }
            }
        }
    }
    priority_queue <pair <ll, pii>, vector <pair <ll, pii>>, greater <pair <ll, pii>>> pq;
    vv <ll> dis(n, m, 1ll << 60);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '.') {
        dis[i][j] = 0;
        pq.emplace(dis[i][j], mp(i, j));
    }
    while (!pq.empty()) {
        ll d = pq.top().X; int x, y; tie(x, y) = pq.top().Y; pq.pop();
        if (d != dis[x][y])
            continue;
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && ccnum[x][y] == ccnum[nx][ny]) {
                if (!count(all(need[k]), s[nx][ny]))
                    continue;
                if (dis[nx][ny] > dis[x][y] + cost[k]) {
                    dis[nx][ny] = dis[x][y] + cost[k];
                    pq.emplace(dis[nx][ny], mp(nx, ny));
                }
            }
        }
    }
    ll ans = 1ll << 60;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] != '#') {
        if (i + 1 < n && s[i + 1][j] != '#')
            ans = min(ans, dis[i][j] + dis[i + 1][j]);
        if (j + 1 < m && s[i][j + 1] != '#')
            ans = min(ans, dis[i][j] + dis[i][j + 1]);
    }
    cout << (ans == 1ll << 60 ? -1 : ans) << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}