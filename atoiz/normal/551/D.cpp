#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long mod;

typedef vector< vector<long long> > Matrix;
Matrix fibMat = {{1, 1}, {1, 0}};

Matrix operator* (const Matrix& a, const Matrix& b)
{
    if (a[0].size() != b.size()) exit(12345);
	int m = a.size(), n = b.size(), p = b[0].size();
    Matrix c(m, vector<long long>(p, 0));
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < p; ++k) {
            for (int j = 0; j < n; ++j) {
                c[i][k] += a[i][j] * b[j][k];
                c[i][k] %= mod;
            }
        }
    }
    return c;
}

Matrix powMat(Matrix a, long long p)
{
    Matrix ans = a; --p;
    int bit = 0;
    while (p > 0) {
        if (p & (1ll << bit)) {
            ans = ans * a;
			p ^= (1ll << bit);
        }
        a = a * a;
        ++bit;
    }
    return ans;
}

long long powInt(long long a, long long p)
{
	long long ans = 1;
    int bit = 0;
    while (p > 0) {
        if (p & (1ll << bit)) {
            ans = (ans * a) % mod;
			p ^= (1ll << bit);
        }
        a = (a * a) % mod;
        ++bit;
    }
    return ans;
}


long long fib(long long x)
{
    Matrix m = powMat(fibMat, x-1);
	return m[0][0];
}

int main()
{
	long long n, k;
	int l;
	cin >> n >> k >> l >> mod;
	if (l == 0 && k == 0) {
		cout << 1 % mod << endl;
		return 0;
	}

    if (mod == 1 || l == 0 || (l < 63 && k >= (1ll << l))) {
		cout << 0 << endl;
		return 0;
    }
    long long ans = 1;
    long long p = powInt(2, n), f = fib(n+2);
    long long g = (p - f + mod) % mod;
    for (int i = 0; i < l; ++i) {
        if (i < 63 && k & (1ll << i)) {
            ans = (ans * g) % mod;
        } else {
			ans = (ans * f) % mod;
        }
    }
    cout << ans << endl;
}