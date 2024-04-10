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

void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    cin >> a;
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    auto diff = [&](int x, int y) -> int {
        int cnt = 0;
        forn (i, 0, m)
            if (a[x][i] != a[y][i])
                cnt++;
        return cnt;
    };
    auto diff_str = [&](string& s, int y) -> int {
        int cnt = 0;
        forn (i, 0, m)
            if (s[i] != a[y][i])
                cnt++;
        return cnt;
    };
    pii t = {-1, -1};
    forn (i, 0, n)
        forn (j, i + 1, n) {
            if (diff(i, j) > 2) {
                cout << "-1\n";
                return;
            }
            if (diff(i, j) == 2) {
                t = {i, j};
            }
        }
    if (t.fs == -1)
        cout << a[0] << "\n";
    else {
        int x = -1, y;
        forn (i, 0, m) {
            if (a[t.fs][i] != a[t.sc][i]) {
                if (x == -1)
                    x = i;
                else
                    y = i;
            }
        }
        string ans = a[t.fs];
        ans[y] = a[t.sc][y];
        bool ok = true;
        forn (i, 0, n)
            if (diff_str(ans, i) > 1)
                ok = false;
        if (ok) {
            cout << ans << "\n";
            return;
        }
        ans = a[t.fs];
        ans[x] = a[t.sc][x];
        ok = true;
        forn (i, 0, n)
            if (diff_str(ans, i) > 1)
                ok = false;
        if (ok)
            cout << ans << "\n";
        else
            cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}