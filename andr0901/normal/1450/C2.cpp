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

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    cin >> a;
    int non_dots = n * n;
    forn (i, 0, n)
        forn (j, 0, n)
            if (a[i][j] == '.')
                --non_dots;
    auto good = [&](vector<string> a) {
        forn (i, 0, n) {
            forn (j, 0, n) {
                if (a[i][j] == '.')
                    continue;
                if (i >= 2 && a[i][j] == a[i - 1][j] && a[i][j] == a[i - 2][j] ||
                    j >= 2 && a[i][j] == a[i][j - 1] && a[i][j] == a[i][j - 2]) {
                    return false;
                }
            }
        }
        forn (i, 0, n) {
            cout << a[i] << "\n";
        }
        return true;
    };
    forn (x, 0, 3) {
        forn (y, 0, 3) {
            int cnt = 0;
            auto b = a;
            forn (i, 0, n) {
                forn (j, 0, n) {
                    if (a[i][j] == 'X' && (i + j) % 3 == x) {
                        b[i][j] = 'O';
                        ++cnt;
                    }
                }
            }
            if (cnt <= non_dots / 3 && good(b)) {
                return;
            }
        }
    }
    forn (x, 0, 3) {
        forn (y, 0, 3) {
            int cnt = 0;
            auto b = a;
            forn (i, 0, n) {
                forn (j, 0, n) {
                    if (a[i][j] == 'O' && (i + j) % 3 == y) {
                        b[i][j] = 'X';
                        ++cnt;
                    }
                }
            }
            if (cnt <= non_dots / 3 && good(b)) {
                return;
            }
        }
    }
    forn (x, 0, 3) {
        forn (y, 0, 3) {
            int cnt = 0;
            auto b = a;
            forn (i, 0, n) {
                forn (j, 0, n) {
                    if (a[i][j] == 'X' && (i + j) % 3 == x) {
                        b[i][j] = 'O';
                        ++cnt;
                    }
                }
            }
            forn (i, 0, n) {
                forn (j, 0, n) {
                    if (a[i][j] == 'O' && (i + j) % 3 == y) {
                        b[i][j] = 'X';
                        ++cnt;
                    }
                }
            }
            if (cnt <= non_dots / 3 && good(b)) {
                return;
            }
        }
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