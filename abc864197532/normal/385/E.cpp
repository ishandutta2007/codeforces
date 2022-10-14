#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 1000087, abc = 864197532, K = 700;

int mod;

struct mat {
    int n;
    vector <vector <long long>> val;
    mat (int _n, int _mode = 0) : n(_n) {
        // mode 1 -> I, other -> O
        val.assign(n, vector<long long>(n, 0));
        if (_mode == 1) {
            for (int i = 0; i < n; ++i) val[i][i] = 1;
        }
    }
    mat (const mat& M) {
        n = M.n;
        val.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                val[i][j] = M.val[i][j];
            }
        }
    }
    mat operator + (const mat& o) {
        mat ans(o);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.val[i][j] = (ans.val[i][j] + val[i][j]) % mod;
            }
        }
        return ans;
    }
    mat operator * (const mat& o) {
        mat ans(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.val[i][j] = (ans.val[i][j] + val[i][k] * o.val[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    mat operator ^ (long long k) {
        mat ans(n, 1), a(*this);
        for (; k; k >>= 1, a = a * a) {
            if (k & 1) ans = ans * a;
        }
        return ans;
    }
};

int v[6][6] = {2, 1, 1, 0, 1, 0, 1, 2, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
     * x, y, dx, dy, add, 1
     * 2 1 1 0 1 0 1
     * 1 2 0 1 1 0 2
     * 1 1 1 0 1 0 0
     * 1 1 0 1 1 0 1
     * 0 0 0 0 1 1 0
     * 0 0 0 0 0 1 1
     */
    lli x, y, dx, dy, t;
    cin >> mod >> x >> y >> dx >> dy >> t;
    mat M = mat(6, 0);
    for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) M.val[i][j] = v[i][j];
    mat A = M ^ t;
    lli B = (A.val[0][0] * x + A.val[0][1] * y + A.val[0][2] * dx + A.val[0][3] * dy + A.val[0][5]) % mod;
    lli C = (A.val[1][0] * x + A.val[1][1] * y + A.val[1][2] * dx + A.val[1][3] * dy + A.val[1][5]) % mod;
    if (B <= 0) B += mod;
    if (C <= 0) C += mod;
    cout << B << ' ' << C << endl;
}