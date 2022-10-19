#include <iostream>

using namespace std;

const int MAXN = 409, MOD = 1000000007;
int f[MAXN][MAXN + 9];

int main()
{
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		f[i][0] = 1;
		for (int j = 1; j < MAXN - i; ++j) {
			for (int k = 0; k <= j; ++k) {
				f[i][j] = (f[i][j] + 1ll * f[i - 1][k] * f[i - 1][j - k]) % MOD;
			}

			for (int k = 0; k < j; ++k) {
				f[i][j] = (f[i][j] + 1ll * f[i - 1][k] * f[i - 1][j - 1 - k]) % MOD;
			}

			for (int k = 0; k <= j; ++k) {
				f[i][j] = (f[i][j] + 2ll * f[i - 1][k + 1] * (k + 1) % MOD * k % MOD * f[i - 1][j - k]) % MOD;
			}

			for (int k = 1; k <= j; ++k) {
				f[i][j] = (f[i][j] + 4ll * f[i - 1][k] * k % MOD * f[i - 1][j - k]) % MOD;
			}

			for (int k = 0; k < j; ++k) {
				f[i][j] = (f[i][j] + 2ll * f[i - 1][k + 1] * (k + 1) % MOD * f[i - 1][j - k] % MOD * (j - k)) % MOD;
			}
		}
	}
	int n;
	cin >> n;
	cout << f[n][1] << endl;
}