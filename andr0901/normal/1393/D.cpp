//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    auto solve = [&](vector <string>& a) {
        vector <vector <int>> right(n, vector <int> (m));
        forn (i, 0, n)
            for (int j = m - 1; j >= 0; --j)
                if (j != m - 1 && a[i][j] == a[i][j + 1])
                    right[i][j] = right[i][j + 1] + 1;
                else
                    right[i][j] = 1;
        vector <vector <int>> up(n, vector <int> (m));
        forn (i, 0, n)
            forn (j, 0, m) {
                up[i][j] = 1;
                int x = i - 1, y = j + 1;
                if (!(0 <= x && x < n &&
                      0 <= y && y < m))
                    continue;
                if (a[i][j] != a[x][y])
                    continue;
                up[i][j] = min(up[x][y] + 1, (right[i][j] + 1) / 2);
            }
        forn (i, 0, n)
            cerr << right[i] << "\n";
        forn (i, 0, n)
            cerr << up[i] << "\n";
        return up;
    };
    vector <string> a(n);
    cin >> a;
    vector <vector <int>> up = solve(a);
    reverse(all(a));
    auto down = solve(a);
    reverse(all(down));
    forn (i, 0, n)
        cerr << up[i] << "\n";
    long long ans = 0;
    forn (i, 0, n)
        forn (j, 0, m)
            ans += min(up[i][j], down[i][j]);
    cout << ans;
    return 0;
}