#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <cmath>

using namespace std;

int n;
std::string str;

const long long mod = 1e9 + 7;
std::vector<long long> hashS;

long long modPow(long long n, long long k) {
	if (k == 0)
		return 1;
	n %= mod;
	if (k & 1)
		return (n*modPow(n, k - 1)) % mod;
	return modPow(n*n, k >> 1);
}

long long getHash(int i, int j) {
	long long h = hashS[j];
	if (i > 0)
		h -= (hashS[i - 1] * modPow(10, j - i + 1)) % mod;
	return (h + mod) % mod;
}

bool check(int i, int j) {
	return (getHash(0, i - 1) + getHash(i, j - 1) - getHash(j, n - 1)) % mod == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	n = str.length();
	
	hashS.resize(n);

	hashS[0] = str[0] - '0';
	for (int i = 1; i < n; ++i)
		hashS[i] = (hashS[i - 1] * 10 + str[i] - '0') % mod;

	for (int j = 1; j < n; ++j) {
		int len3 = n - j;
		if (len3 > 1 && str[j] == '0')
			continue;
		std::set<int> seti = { len3 - 1, len3-2, len3 + 1, len3, j - len3, j + 1 - len3, j -1 - len3, j +2- len3, j -2- len3 };
		for (auto &&i : seti) {
			if (i <= 0 || i >= j)
				continue;
			if (i > 1 && str[0] == '0')
				continue;
			if (j - i > 1 && str[i] == '0')
				continue;
			if (check(i, j)) {
				std::cout << str.substr(0, i) << "+" << str.substr(i, j - i) << '=' << str.substr(j);
				return 0;
			}
		}
	}
	return 0;
}