#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
const int N = 2001, logN = 20, K = 111;

int a[N][N];
lli dis[N][N][2];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        dis[i][j][0] = dis[i][j][1] = -1;
    }
    {
        queue <pii> q;
        q.emplace(0, 0);
        dis[0][0][0] = 0;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != -1 && dis[nx][ny][0] == -1) {
                    dis[nx][ny][0] = dis[x][y][0] + w;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    {
        queue <pii> q;
        q.emplace(n - 1, m - 1);
        dis[n - 1][m - 1][1] = 0;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != -1 && dis[nx][ny][1] == -1) {
                    dis[nx][ny][1] = dis[x][y][1] + w;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    lli ans = (dis[n - 1][m - 1][0] != -1 ? dis[n - 1][m - 1][0] : 1ll << 60);
    lli teleport[2] = {1ll << 60, 1ll << 60};
    for (int t : {0, 1}) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (dis[i][j][t] != -1 && a[i][j]) {
                teleport[t] = min(teleport[t], dis[i][j][t] + a[i][j]);
            }
        }
    }
    ans = min(ans, teleport[0] + teleport[1]);
    if (ans == 1ll << 60) ans = -1;
    cout << ans << endl;
}