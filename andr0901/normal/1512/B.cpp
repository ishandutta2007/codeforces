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
    vector<pii> b;
    forn (i, 0, n) {
        forn (j, 0, n) {
            if (a[i][j] == '*') {
                b.eb(i, j);
            }
        }
    }
    if (b[0].fs == b[1].fs) {
        if (b[0].fs == 0) {
            a[1][b[0].sc] = a[1][b[1].sc] = '*';
        } else {
            a[0][b[0].sc] = a[0][b[1].sc] = '*';
        }
    } else if (b[0].sc == b[1].sc) {
        if (b[0].sc == 0) {
            a[b[0].fs][1] = a[b[1].fs][1] = '*';
        } else {
            a[b[0].fs][0] = a[b[1].fs][0] = '*';
        }
    } else {
        a[b[0].fs][b[1].sc] = a[b[1].fs][b[0].sc] = '*';
    }
    forn (i, 0, n)
        cout << a[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}