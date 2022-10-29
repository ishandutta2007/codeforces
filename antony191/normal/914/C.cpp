#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <bitset>


using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int sumod(bitset<1000> s);
int mod2(int a);
int bit1(int a);
int cofntok(bitset<1000> s, int n, int k);

int main() {
	string tmp;
	int k;
	cin >> tmp;
	bitset<1000> s(tmp);
	cin >> k;
	if (k == 0) {
		return cout << 1, 0;
	}
	int n = tmp.size();
	int sum = 0;
	vector<int> a(n + 1);
	a[1] = 0;
	for (int i = 2; i <= n; ++i) {
		a[i] = a[bit1(i)] + 1;
	}
	vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> co(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; ++i) {
		c[i][0] = 1;
		co[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
			c[i][j] %= mod;
			if (s[i - 1]) {
				co[i][j] = c[i - 1][j] + co[i - 1][j - 1];
				co[i][j] %= mod;
			}
			else {
				co[i][j] = co[i - 1][j];
			}
		}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == k - 1) {
			sum += co[n][i];
			if (i == 1)
				--sum;
			sum %= mod;
		}
	}
	cout << (sum % mod + mod) % mod;
	return 0;
}

int bit1(int a) {
	int sum = 0;
	while (a > 0) {
		if ((a & 1) == 1)
			++sum;
		a >>= 1;
	}
	return sum;
}
/*
int mod2(int a) {
	int ans = 1;
	for (int i = 0; i < a; ++i) {
		ans <<= 1;
		if (ans > 500000000)
			ans %= mod;
	}
	ans = (ans % mod + mod) % mod;
	return ans;
}
int sumod(bitset<1000> s) {
	int sum = 0;
	for (int i = 0; i < 1000; ++i) {
		if (s[i]) {
			sum += mod2(i);
			if (sum >= mod)
				sum %= mod;
		}
	}
	sum = (sum % mod + mod) % mod;
	return sum;
}

int cofntok(bitset<1000> s, int n, int k) {
	if (k == n) {
		bool t = true;
		for (int i = 0; i < n; ++i)
			if (!s[i]) {
				k = false;
				break;
			}
		if (t)
			return 1;
		return 0;
	}
	vector<vector<int>> a(k, vector<int>(n - k, 0));
	
}*/