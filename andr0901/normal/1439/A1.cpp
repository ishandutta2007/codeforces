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
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    cin >> a;
    forn (i, 0, n)
        forn (j, 0, m)
            a[i][j] -= '0';
    vector <vector <int>> ans;
    auto apply = [&](vector <int> t) {
        for (int i = 0; i < t.size(); i += 2) {
            int x = t[i], y = t[i + 1];
            a[x][y] ^= 1;
        }
        ans.pb(t);
        /*forn (i, 0, n) {
            forn (j, 0, m)
                cerr << (int)(a[i][j]);
            cerr << "\n";
        }
        cerr << "\n";*/
    };
    forn (i, 0, n - 1) {
        forn (j, 0, m - 1) {
            if (a[i][j] && a[i][j + 1]) {
                apply({i, j, i, j + 1, i + 1, j});
            } else if (a[i][j] && !a[i][j + 1]) {
                apply({i, j, i + 1, j, i + 1, j + 1});
            }
        } 
    }
    /*forn (i, 0, n - 1) {
        forn (j, 0, m - 1) {
            if (a[i][j] == 1) {
                apply({i, j, i, j + 1, i + 1, j + 1});
                apply({i, j, i + 1, j, i + 1, j + 1});
                apply({i, j, i, j + 1, i + 1, j});
            }
        }
    }*/
    forn (i, n - 1, n) {
        forn (j, 0, m - 1) {
            if (a[i][j] == 1) {
                apply({i, j, i - 1, j + 1, i, j + 1});
                apply({i - 1, j, i - 1, j + 1, i, j});
                apply({i - 1, j, i, j, i, j + 1});
            }
        }
    }
    forn (i, 0, n - 1) {
        forn (j, m - 1, m) {
            if (a[i][j] == 1) {
                apply({i, j, i, j - 1, i + 1, j - 1});
                apply({i, j - 1, i, j, i + 1, j});
                apply({i, j, i + 1, j - 1, i + 1, j});
            }
        }
    }
    if (a[n - 1][m - 1]) {
        int i = n - 1, j = m - 1;
        apply({i - 1, j - 1, i - 1, j, i, j});
        apply({i - 1, j - 1, i, j - 1, i, j});
        apply({i - 1, j, i, j, i, j - 1});
    }
    map <vector <pii>, int> used;
    for (auto& x : ans) {
        vector <pii> t(3);
        for (int i = 0; i < sz(x); i += 2)
            t[i / 2] = {x[i], x[i + 1]};
        sort(all(t));
        used[t] ^= 1; 
    }
    int k = 0;
    for (auto& i : used)
        if (i.sc == 1)
            ++k;
    cout << k << "\n";
    for (auto& i : used) {
        if (i.sc == 1) {
            forn (j, 0, 3)
                cout << i.fs[j].fs + 1  << " " << i.fs[j].sc + 1 << " ";
            cout << "\n";
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