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

int n;
vector <vector <long long>> a;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a.resize(n, vector <long long> (n));
    a[0][1] = 2, a[1][0] = 1;
    forn (i, 2, n) {
        a[i][0] = a[i - 1][0] * 2;
        a[0][i] = a[0][i - 1] * 2; 
    }
    forn (i, 1, n) {
        forn (j, 1, n) {
            a[i][j] = a[i][j - 1] + a[i - 1][j];
        }
    }
    forn (i, 0, n)
        cerr << a[i] << "\n";
    cerr << "---\n";
    vector <vector <long long>> mn(n, vector <long long> (n));
    auto mx = mn;
    forn (i, 0, n) {
        forn (j, 0, n) {
            int x = 0, y = 0;
            while (x != i) {
                mn[i][j] += a[x][y];
                ++x;
            }
            while (y != j) {
                mn[i][j] += a[x][y];
                ++y;
            }
            x = 0, y = 0;
            while (y != j) {
                mx[i][j] += a[x][y];
                ++y;
            }
            while (x != i) {
                mx[i][j] += a[x][y];
                ++x;
            }
        }
        cerr << mn[i] << "\n";
    }
    cerr << "---\n";
    forn (i, 0, n)
        cerr << mx[i] << "\n";
    forn (i, 0, n)
        cout << a[i] << endl;
    int q;
    cin >> q;
    while (q --> 0) {
        long long s;
        cin >> s;
        vector <pii> ans;
        int x = n - 1, y = n - 1;
        while (!(x == 0 && y == 0)) {
            ans.eb(x, y);
            s -= a[x][y];
            if (x && s >= mn[x - 1][y] + a[x - 1][y])
                --x;
            else
                --y;
        }
        ans.eb(x, y);
        reverse(all(ans));
        for (auto [x, y] : ans)
            cout << x + 1 << " " << y + 1 << endl;
    }
    return 0;
}