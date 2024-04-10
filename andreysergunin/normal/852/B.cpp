#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * b;
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

typedef vector<vector<int> > matrix;

matrix operator*(const matrix& a, const matrix& b) {
	int n = sz(a), k = sz(b), m = sz(b[0]);
	matrix ans(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int z = 0; z < k; ++z) {
				int val = a[i][z];
				mul(val, b[z][j]);
				add(ans[i][j], val);
			}
		}
	}
	return ans;
}

matrix binpow(matrix a, int n) {
	int k = sz(a);
	matrix ans(k, vector<int>(k));
	for (int i = 0; i < k; ++i) {
		ans[i][i] = 1;
	}
	while (n) {
		if (n & 1) {
			ans = ans * a;
		}
		n >>= 1;
		a = a * a;
	}
	return ans;
}

int main() {

    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, l, m;
	scanf("%d%d%d", &n, &l, &m);

	matrix ans = vector<vector<int> >(m, vector<int>(1));
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		++ans[val % m][0];
	}

	vector<int> cnt(m, 0);
	vector<int> cost1(n);
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		cost1[i] = val;
		++cnt[val % m];
	}

	matrix base(m, vector<int>(m));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			int r = (i - j + m) % m;
			base[i][j] = cnt[r];
		}
	}

	matrix deg = binpow(base, l - 2);
	ans = deg * ans;

	vector<int> cost2(n);
	cnt.assign(m, 0);
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		cost2[i] = val;
		++cnt[(cost1[i] + cost2[i]) % m];
	}

	base = vector<vector<int> >(m, vector<int>(m));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			int r = (i - j + m) % m;
			base[i][j] = cnt[r];
		}
	}
	ans = base * ans;

	cout << ans[0][0] << "\n";

}