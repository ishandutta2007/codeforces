#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <bitset>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define forit(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define sz(a) (int)a.size()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

struct Matrix {
    double a[130][130];
    int sz;

    Matrix () {}
    Matrix (int _sz, double b[][130]) {
        sz = _sz;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) a[i][j] = b[i][j];
        }
    }

    Matrix const operator *(Matrix o) {
        double c[130][130];
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                c[i][j] = 0;
                for (int t = 0; t < sz; t++) {
                    c[i][j] += a[i][t] * o.a[t][j];
                }
            }
        }
        return Matrix(sz, c);
    }
} zero;

int n, x;
double p[1111], bit[1111];

Matrix binpow(Matrix a, int k) {
    if (k == 0) return zero;
    Matrix ans = binpow(a, k / 2);
    ans = ans * ans;
    if (k % 2) ans = ans * a;
    return ans;
}

int main () {

    cin >> n >> x;
    for (int i = 0; i <= x; i++) {
        cin >> p[i];
        for (int j = 0; j < 8; j++) {
            if ((1 << j)&i) bit[j] += p[i];
        }
    }

    int len = 1;
    while (len <= x) len *= 2;
    double a[130][130], b[130][130];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            a[i][j] = 0;
            b[i][j] = 0;
        }
        b[i][i] = 1;
    }

    for (int val = 0; val < len; val++) {
        for (int j = 0; j < len; j++) {
            a[j][val] = p[j^val];
        }
    }

    Matrix A = Matrix(len, a);
    zero = Matrix(len, b);

    double ans = 0;

    A = binpow(A, n - 1);

    for (int i = 0; i < len; i++) ans += p[i] * A.a[i][0];

    printf("%.8f\n", 1.0 - ans);

	return 0;
}