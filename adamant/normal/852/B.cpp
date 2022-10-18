#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define pb emplace_back
#define mp make_pair

typedef long long ll;
typedef double lf;

#define int ll
const int maxmod = 100;
const int MOD = 1000000000 + 7;


int n, l, mod;
int c[3][maxmod], res[2][maxmod];
vector<int> nums[3];

struct matr {
	int a[maxmod][maxmod];

	matr() {
		memset(a, 0, sizeof(a));
	}

	matr operator * (const matr &m) const {
		matr res;
		int MMOD = MOD * MOD;
		//for (int i = 0; i < mod; ++i) {
		//  for (int j = 0; j < i; ++j) {
		//    swap(m.a[i][j], m.a[j][i]);
		//  }
		//}
		for (int i = 0; i < mod; ++i) {
			for (int j = 0; j < mod; ++j) {
				for (int z = 0; z < mod; ++z) {
					//res.a[i][j] += a[i][z] * m.a[j][z];
					res.a[i][j] += a[i][z] * m.a[z][j];
					if (res.a[i][j] >= MMOD) {
						res.a[i][j] -= MMOD;
					}
				}
				res.a[i][j] %= MOD;
			}
		}
		//for (int i = 0; i < mod; ++i) {
		//  for (int j = 0; j < i; ++j) {
		//    swap(m.a[i][j], m.a[j][i]);
		//  }
		//}
		return res;
	}
};

matr power(const matr &a, int p) {
	matr curp = a, res;
	for (int i = 0; i < mod; ++i) res.a[i][i] = 1;
	for (; p; p >>= 1) {
		if (p & 1) res = res * curp;
		curp = curp * curp;
	}
	return res;
}

signed main() {
	srand(131);
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> mod;
	for (int it = 0; it < 3; ++it) {
		for (int i = 0; i < n; ++i) {
			int cost;
			cin >> cost;
			nums[it].push_back(cost);
			++c[it][cost % mod];
		}
	}
	matr m;
	for (int x = 0; x < mod; ++x) {
		for (int i = 0; i < mod; ++i) {
			m.a[x][(x + i) % mod] += c[1][i];
		}
	}
	m = power(m, l - 2);
	fill(c[2], c[2] + mod, 0);
	for (int i = 0; i < n; ++i) {
		++c[2][(nums[1][i] + nums[2][i]) % mod];
	}
	for (int i = 0; i < mod; ++i) {
		for (int j = 0; j < mod; ++j) {
			res[0][j] += c[0][i] * m.a[i][j] % MOD;
			if (res[0][j] >= MOD) res[0][j] -= MOD;
		}
	}
	for (int i = 0; i < mod; ++i) {
		for (int j = 0; j < mod; ++j) {
			res[1][(i + j) % mod] += res[0][i] * c[2][j] % MOD;
			if (res[1][(i + j) % mod] >= MOD) {
				res[1][(i + j) % mod] -= MOD;
			}
		}
	}
	cout << res[1][0] << endl;
	return 0;
}