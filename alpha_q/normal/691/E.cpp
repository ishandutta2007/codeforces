#include <bits/stdc++.h>

using namespace std;

#define DIM 105
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 110;

struct matrix {
    vector < vector <long long> > m;
    int r, c;
    matrix (int x, int y) : r(x), c(y) {
        m.resize(x);
        for(int i = 0; i < x; i++) m[i].resize(y);
    }
    matrix () {}
    matrix operator * (const matrix &e) {
        matrix ans (r, e.c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < e.c; j++) {
                for(int k = 0; k < c; k++) {
                    ans.m[i][j] += m[i][k] * e.m[k][j];
                    ans.m[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
    void print() {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cerr << m[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << endl;
    }
};

int n; ll k, x[N];

ll check (ll p, ll q) {
    ll z = p ^ q;
    int b = __builtin_popcountll(z);
    return b % 3 ? 0LL : 1LL;
}

ll expo (matrix &in, ll p) {
    matrix ret(n, n);
    for (int i = 0; i < n; ++i) ret.m[i][i] = 1;
    while (p) {
        if (p & 1) ret = ret * in;
        in = in * in;
        p >>= 1;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res = (res + ret.m[i][j]) % MOD;
    return res;
}

int main (int argc, char const *argv[]) {
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%I64d", x + i);
    matrix M(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
             M.m[i][j] = check(x[i], x[j]);
    printf("%I64d\n", expo(M, k - 1));
    return 0;
}