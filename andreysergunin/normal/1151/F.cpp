#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int binPow(int a, int n) {
    int res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

int rev(int a) {
    return binPow(a, P - 2);
}

struct Matrix {
    vector<vector<int>> a;

    Matrix() {}
    Matrix(int n) {
        a.resize(n, vector<int>(n));
    }

    vector<int>& operator[](int pos) {
        return a[pos];
    }

    const vector<int>& operator[](int pos) const {
        return a[pos];
    }

    Matrix operator*(const Matrix &other) {
        int n = sz(a);
        Matrix res(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n ; ++j) {
                for (int k = 0; k < n; ++k) {
                    int cur = a[i][k];
                    mul(cur, other[k][j]);
                    add(res[i][j], cur);
                }
            }
        }
        return res;
    }

    size_t size() {
        return sz(a);
    }
};

Matrix e(int n) {
    Matrix res(n);
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    return res;
}

Matrix binPow(Matrix a, int n) {
    Matrix res = e(sz(a));
    for (; n > 0; n >>= 1)  {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);



    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m += a[i];
    }

    int cnt = 0;
    for (int i = n - m; i < n; ++i) {
        cnt += a[i];
    }

    Matrix mat(m + 1);

    int r = rev(n * (n - 1) / 2);

    for (int i = 0; i <= m; ++i) {
        if (n - m  < m - i) {
            continue;
        }
        int p = 1;

        if (i > 0) {
            int a = i;
            int b = (n - m) - (m - i);
            mul(a, b);
            mul(a, r);
            mat[i][i - 1] = a;
            sub(p, a);
        }

        if (i < m) {
            int a = m - i;
            int b = m - i;
            mul(a, b);
            mul(a, r);
            mat[i][i + 1] = a;
            sub(p, a);
        }

        mat[i][i] = p;
    }   

    // for (int i = 0; i <= m; ++i) {
    //     for (int j = 0; j <= m; ++j) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    mat = binPow(mat, k);

    cout << mat[cnt][m] << endl;
}