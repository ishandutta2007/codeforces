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

vector<vector<int>> a;

void dfs(int x, int y, int& cnt, int col) {
    cerr << x << " " << y << " " << cnt << " " << col << "\n";
    if (cnt <= 0) {
        return;
    }
    if (a[x][y]) {
        return;
    }
    a[x][y] = col;
    --cnt;
    if (y - 1 >= 0) {
        dfs(x, y - 1, cnt, col);
    }
    if (x + 1 < a.size()) {
        dfs(x + 1, y, cnt, col);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    a.resize(n, vector<int>(n));
    forn (i, 0, n) {
        dfs(i, i, p[i], p[i]);
    }
    forn (i, 0, n) {
        forn (j, 0, i + 1) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}