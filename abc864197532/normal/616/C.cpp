#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17, K = 3e6;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

struct Dsu {
    int dsu[N], size[N], cc;
    Dsu () {
        for (int i = 0; i < N; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
} dsu;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (s[i][j] == '.' && s[ni][nj] == '.') dsu.Union(i * m + j, ni * m + nj);
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '*') {
        set <int> se;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (s[ni][nj] == '.') se.insert(dsu.Find(ni * m + nj));
        }
        int ans = 1;
        for (int i : se) ans += dsu.size[i];
        s[i][j] = ans % 10 + '0';
    }
    for (int i = 0; i < n; ++i) cout << s[i] << '\n';
}