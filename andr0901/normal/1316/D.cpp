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

#define x first
#define y second

vector <vector <pii>> a;
vector <vector <char>> ans;

int n;

bool valid(int x, int y) {
    return 0 <= x && x < n &&
           0 <= y && y < n;
}

vector <int> dx, dy;
vector <char> d;

bool equal(pii a, pii b) {
    return a.x == b.x && a.y == b.y;
}


void dfs(int x, int y, char dir) {
    ans[x][y] = dir;
    forn (i, 0, 4) {
        int X = x + dx[i], Y = y + dy[i];
        if (valid(X, Y) && !ans[X][Y] && equal(a[X][Y], a[x][y]))
            dfs(X, Y, d[i]);
    }
}

bool inf(pii a) {
    return (a.x == -2 && a.y == -2);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    dx = {-1, 1, 0, 0};
    dy = {0, 0, -1, 1};
    d  = {'D', 'U', 'R', 'L'};
    cin >> n;
    a.resize(n, vector <pii> (n));
    forn (i, 0, n)
        forn (j, 0, n)
            cin >> a[i][j].x >> a[i][j].y, a[i][j].x--, a[i][j].y--;

    ans.resize(n, vector <char> (n));
    forn (i, 0, n)
        forn (j, 0, n)
            if (!ans[i][j] && i == a[i][j].x && j == a[i][j].y)
                dfs(i, j, 'X');

    forn (i, 0, n - 1) {
        forn (j, 0, n) {
            if (ans[i][j] || !inf(a[i][j]))
                continue;
            if (ans[i + 1][j] || !inf(a[i + 1][j]))
                continue;
            dfs(i, j, 'D'), dfs(i + 1, j, 'U');
        }
    }
    forn (i, 0, n) {
        forn (j, 0, n - 1) {
            if (ans[i][j] || !inf(a[i][j]))
                continue;
            if (ans[i][j + 1] || !inf(a[i][j + 1]))
                continue;
            dfs(i, j, 'R'), dfs(i, j + 1, 'L');
        }
    }

    forn (i, 0, n)
        forn (j, 0, n)
            if (!ans[i][j])
                return cout << "INVALID", 0;
    cout << "VALID\n";
    forn (i, 0, n) {
        forn (j, 0, n)
            cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}