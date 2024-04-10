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
    vector<string> a(n);
    cin >> a;
    int ans = 0;
    int x = 0, y = 0;
    while (true) {
        cerr << x << " " << y << "\n";
        bool done = false;
        forn (sum, 0, n + m - 1) {
            forn (dx, 0, n) {
                int nx = x + dx;
                int ny = y + sum - dx;
                if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) {
                    continue;
                }
                if (!(x <= nx && y <= ny)) {
                    continue;
                }
                if (a[nx][ny] == '*') {
                    ++ans;
                    done = true;
                    x = nx, y = ny;
                    a[x][y] = '.';
                    break;
                }
            }
            if (done) {
                break;
            }
        }
        if (!done) {
            cout << ans << "\n";
            return 0;
        }
    }
    return 0;
}