#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <array>
#include <string>

using namespace std;

const int mod = 1e9 + 7;

array<int, 26> getOcc(const string &s) {
	array<int, 26> occ = { 0 };
	for (auto &&c : s)
		++occ[c - 'a'];
	return occ;
}

int modPow(long long n, int k) {
	int res = 1;
	n %= mod;
	while (k) {
		if (k & 1)
			res = (res * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}
	return res;
}

int inv(long long x) {
	return modPow(x, mod - 2);
}

vector<int> fact;
vector<int> factInv;

int updateMulti(long long multi, int total, int bag) {
	multi = (multi * factInv[total]) % mod;
	multi = (multi * fact[total - 1]) % mod;
	multi = (multi * fact[bag]) % mod;
	multi = (multi * factInv[bag - 1]) % mod;
	return multi;
}

int f(int i, const int multi, array<int, 26> &occ, const string &b) {
	if (i == b.size())
		return 1;
	int res = 0;
	if (occ[b[i] - 'a']) {
		--occ[b[i] - 'a'];
		res += f(i + 1, updateMulti(multi, b.size() - i, occ[b[i] - 'a'] + 1), occ, b);
		++occ[b[i] - 'a'];
	}
	for (int j = 0; j < b[i] - 'a'; ++j)
		if (occ[j])
			res = (res + updateMulti(multi, b.size() - i, occ[j])) % mod;
	return res;
}

int f(array<int, 26> &occ, const string &b) {
	long long multi = fact[b.size()];
	for (int i = 0; i < 26; ++i)
		multi = (multi * factInv[occ[i]]) % mod;
	return f(0, multi, occ, b);
}

int main() {
	string a, b;
	cin >> a >> b;

	fact.resize(a.size() + 1, 1);
	factInv.resize(fact.size(), 1);
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = ((long long)fact[i - 1] * i) % mod;
		factInv[i] = inv(fact[i]);
	}

	// (a, b) = ( , b) - ( , a]

	auto occ = getOcc(a);
	long long ans = (f(occ, b) - f(occ, a) - (occ == getOcc(b)) + ((long long)mod << 1)) % mod;
	cout << ans;
	return 0;
}