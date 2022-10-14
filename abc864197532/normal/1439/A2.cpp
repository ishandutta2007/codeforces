#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 100;

struct op {
    int x1, y1, x2, y2, x3, y3;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m, 0));
    string s;
    fop (i,0,n) {
        cin >> s;
        fop (j,0,m) a[i][j] = s[j] - '0';
    }
    vector <op> ans;
    auto add = [&](int i, int j, int k, int ii, int jj, int kk) {
        ans.pb({i + 1, j + 1, k + 1, ii + 1, jj + 1, kk + 1});
        a[i][j] ^= 1;
        a[k][ii] ^= 1;
        a[jj][kk] ^= 1;
    };
    fop (i,0,n - 2) {
        fop (j,0,m - 1) {
            if (a[i][j] == 1) {
                add(i, j, i, j + 1, i + 1, j + 1);
            }
        }
        if (a[i][m - 1] == 1) {
            add(i, m - 1, i + 1, m - 2, i + 1, m - 1);
        }
    }
    fop (j,0,m - 2) {
        if (a[n - 2][j] == 1) add(n - 2, j, n - 2, j + 1, n - 1, j + 1);
        if (a[n - 1][j] == 1) add(n - 1, j, n - 1, j + 1, n - 2, j + 1);
    }
    if (a[n - 2][m - 2] + a[n - 2][m - 1] + a[n - 1][m - 2] + a[n - 1][m - 1] == 4) {
        add(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
    }
    if (a[n - 2][m - 2] + a[n - 2][m - 1] + a[n - 1][m - 2] + a[n - 1][m - 1] == 1) {
        if (a[n - 2][m - 1] != 1) {
            add(n - 2, m - 2, n - 1, m - 1, n - 1, m - 2);
        } else {
            add(n - 2, m - 2, n - 1, m - 1, n - 2, m - 1);
        }
    }
    if (a[n - 2][m - 2] + a[n - 2][m - 1] + a[n - 1][m - 2] + a[n - 1][m - 1] == 2) {
        if (a[n - 2][m - 2] == 1) {
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
        }
        else if (a[n - 2][m - 1] == 1) {
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 2);
        }
        else if (a[n - 1][m - 2] == 1) {
            add(n - 2, m - 2, n - 1, m - 1, n - 2, m - 1);
        }
        else if (a[n - 1][m - 1] == 1) {
            add(n - 1, m - 2, n - 2, m - 2, n - 2, m - 1);
        }
    }
    if (a[n - 2][m - 2] + a[n - 2][m - 1] + a[n - 1][m - 2] + a[n - 1][m - 1] == 3) {
        if (a[n - 2][m - 2] == 0) {
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
        }
        else if (a[n - 2][m - 1] == 0) {
            add(n - 1, m - 2, n - 1, m - 1, n - 2, m - 2);
        }
        else if (a[n - 1][m - 2] == 0) {
            add(n - 2, m - 2, n - 1, m - 1, n - 2, m - 1);
        }
        else if (a[n - 1][m - 1] == 0) {
            add(n - 1, m - 2, n - 2, m - 2, n - 2, m - 1);
        }
    }
    cout << ans.size() << endl;
    for (auto A : ans) cout << A.x1 << ' ' << A.y1 << ' ' << A.x2 << ' ' << A.y2 << ' ' <<A.x3 << ' ' << A.y3 << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}