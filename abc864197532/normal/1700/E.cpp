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
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 600001, logN = 18, B = 1 << 8, M = 1 << 21;

int dx[5] = {1, -1, 0, 0, 0}, dy[5] = {0, 0, 1, -1, 0};

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vv <int> a(n, m, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
        cin >> a[i][j], --a[i][j];
    vv <bool> ok(n, m, false);
    auto chk = [&](int x, int y) {
        if (!a[x][y])
            return true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[x][y] > a[nx][ny])
                return true;
        }
        return false;
    };
    int sum = 0, all = 0, stx = -1, sty = -1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        ok[i][j] = chk(i, j), sum += ok[i][j];
        if (!ok[i][j]) {
            stx = i, sty = j, all++;
        }
    }
    if (!all) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int k = 0; k < 5; ++k) {
        int i = stx + dx[k], j = sty + dy[k];
        if (i < 0 || i >= n || j < 0 || j >= m)
            continue;
        for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) if (i != x || j != y) {
            int now = sum;
            vector <pii> res;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m)
                    res.eb(nx, ny);
            }
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m)
                    res.eb(nx, ny);
            }
            res.eb(i, j), res.eb(x, y);
            sort(all(res)), res.resize(unique(all(res)) - res.begin());
            swap(a[i][j], a[x][y]);
            for (auto [ii, jj] : res) {
                if (ok[ii][jj])
                    now--;
                now += chk(ii, jj);
            }
            swap(a[i][j], a[x][y]);
            if (now == n * m)
                ans++;
        }
    }
    for (int k = 0; k < 5; ++k) for (int kk = k + 1; kk < 5; ++kk) {
        int i = stx + dx[k], j = sty + dy[k];
        int x = stx + dx[kk], y = sty + dy[kk];
        if (i < 0 || i >= n || j < 0 || j >= m)
            continue;
        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        int now = sum;
        vector <pii> res;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
                res.eb(nx, ny);
        }
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k], ny = j + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
                res.eb(nx, ny);
        }
        res.eb(i, j), res.eb(x, y);
        sort(all(res)), res.resize(unique(all(res)) - res.begin());
        swap(a[i][j], a[x][y]);
        for (auto [ii, jj] : res) {
            if (ok[ii][jj])
                now--;
            now += chk(ii, jj);
        }
        swap(a[i][j], a[x][y]);
        if (now == n * m)
            ans--;
    }
    if (!ans)
        cout << 2 << endl;
    else
        cout << 1 << ' ' << ans << endl;
}