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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vector <string> a(n);
    cin >> a;
    deque <pii> q;
    vector <int> dx = {0, 0, 1, -1};
    vector <int> dy = {-1, 1, 0, 0};
    auto good = [&](int x, int y) {
        return 0 <= x && x < n &&
               0 <= y && y < m;
    };
    const int INF = 1e9;
    vector <vector <int>> dst(n, vector <int> (m, INF));
    forn (i, 0, n)
        forn (j, 0, m) {
            bool to_push = false;
            forn (k, 0, 4) {
                int x = i + dx[k], y = j + dy[k];
                if (good(x, y) && a[x][y] == a[i][j])
                    to_push = true;
            }
            if (to_push) {
                dst[i][j] = 0;
                q.eb(i, j);
            }
        }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop_front();
        forn (k, 0, 4) {
            int x = i + dx[k], y = j + dy[k];
            if (good(x, y) && a[x][y] != a[i][j] && dst[i][j] + 1 < dst[x][y]) {
                dst[x][y] = dst[i][j] + 1;
                q.eb(x, y);
            }
        }
    }
    /*forn (i, 0, n)
        cout << dst[i] << "\n";*/
    auto change = [](char c) {
        if (c == '0')
            return '1';
        else
            return '0';
    };
    while (t --> 0) {
        int x, y;
        long long p;
        cin >> x >> y >> p, --x, --y;
        if (dst[x][y] == INF)
            cout << a[x][y];
        else {
            if (p < dst[x][y]) {
                cout << a[x][y];
            } else {
                if (dst[x][y] % 2 == p % 2)
                    cout << a[x][y];
                else
                    cout << change(a[x][y]);
            }
        }
        cout << "\n";
    }
    return 0;
}