#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int mod1 = 1e9 + 6, mod2 = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 100;

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
    mat (int _n, vector <vector <long long>> num) {
        n = _n;
        val = num;
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
                ans.val[i][j] = (ans.val[i][j] + val[i][j]) % mod1;
            }
        }
        return ans;
    }
    mat operator * (const mat& o) {
        mat ans(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.val[i][j] = (ans.val[i][j] + val[i][k] * o.val[k][j]) % mod1;
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

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod2) {
        if (b & 1) ans = ans * a % mod2;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector <vector <long long>> a = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    vector <vector <long long>> b = {{1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}};
    mat A(3, a), C(5, b);
    mat B = A ^ (n - 3), D = C ^ (n - 3);
    cout << modpow(f1, B.val[0][2]) * modpow(f2, B.val[0][1]) % mod2 * modpow(f3, B.val[0][0]) % mod2 * modpow(c, (D.val[0][3] + D.val[0][4]) * 2) % mod2;
}