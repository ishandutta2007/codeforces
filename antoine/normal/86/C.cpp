#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

class SS {
private:
	static const int offset = 26;
public:
	int w = 0;

	SS(const string s) {
		for (const char &c : s) {
			w <<= 2;
			switch (c) {
			case 'A': w |= 0; break;
			case 'C': w |= 1; break;
			case 'T': w |= 2; break;
			case 'G': w |= 3; break;
			}
		}
		w |= s.length() << offset;
	}

	SS(const int w) : w(w) {}

	int len() const {
		return w >> offset;
	}

	int containsIdx(const SS &o) const {
		const int limit = (len() - o.len()) << 1;
		const int mask = (1 << (o.len() << 1)) - 1;
		for (int i = 0; i <= limit; i += 2) {
			const int xor_ = (w >> i) ^ o.w;
			if (!(xor_ & mask))
				return i >> 1;
		}
		return -1;
	}

	bool isPrefixOf(const SS &o) const {
		if (len() > o.len())
			return false;
		const int mask = (1 << (len() << 1)) - 1;
		const int diff = (o.len() - len()) << 1;
		const int xor_ = (o.w >> diff) ^ w;
		return !(xor_ & mask);
	}

	bool isStrictPrefixOf(const SS &o) const {
		if (len() >= o.len())
			return false;
		const int mask = (1 << (len() << 1)) - 1;
		const int diff = (o.len() - len()) << 1;
		const int xor_ = (o.w >> diff) ^ w;
		return !(xor_ & mask);
	}
	operator int() const {
		return w;
	}

	SS substr1() const {
		const int l = len() - 1; // 1
		const int mask = ~(3 << (l << 1)) & ~(-1 << offset);
		return (l << offset) | (w & mask);
	}

	SS operator+(const char c) const {
		const int l = len() + 1;
		const int mask = ~(-1 << offset);
		return (l << offset) | ((w << 2 | c) & mask);
	}

	friend ostream &operator<<(ostream &out, const SS &ss) {
		for (int i = (ss.len() - 1) << 1; i >= 0; i -= 2) {
			switch ((ss.w >> i) & 3) {
			case 0: out << 'A'; break;
			case 1: out << 'C'; break;
			case 2: out << 'T'; break;
			case 3: out << 'G'; break;
			}
		}
		return out;
	}
};

struct Dict {
	vector<SS> words;

	bool hasStrictPrefix(const SS ss) {
		for (auto &&w : words)
			if (ss.isStrictPrefixOf(w))
				return true;
		return false;
	}

} dict;

const int mod = 1000000009;

map<int, int> dp[1001][11];

int f(const int n, const int i, const SS ss) {

	auto it = dp[n][i].find(ss);
	if (it != dp[n][i].end())
		return it->second;

	//cout << n << ' ' << i << ' ' << ss << '\n';
	//static int noCalls = 0;
	//if (++noCalls > 50)
		//exit(0);

	if (n == 0 && i == ss.len())
		return dp[n][i][ss] = 1;

	for (auto &&w : dict.words)
		if (i < w.len() && w.isPrefixOf(ss))
				return dp[n][i][ss] = f(n, i + 1, ss);
	
	if (n == 0 || !dict.hasStrictPrefix(ss))
		return dp[n][i][ss] = i ? f(n, i - 1, ss.substr1()) : 0;

	int ans = 0;
	if (ss.len() == 10) {
		if (i == 0)
			return dp[n][i][ss] = 0;
		SS ss1 = ss.substr1();
		for (char c = 0; c < 4; ++c)
			ans = (ans + f(n - 1, i - 1, ss1 + c)) % mod;
	}
	else
		for (char c = 0; c < 4; ++c)
			ans = (ans + f(n - 1, i, ss + c)) % mod;
	return dp[n][i][ss] = ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		dict.words.emplace_back(s);
	}

	cout << f(n, 0, 0);
	return 0;
}