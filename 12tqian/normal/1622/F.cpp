#include <bits/stdc++.h>

using namespace std;

#line 2 "misc/rng.hpp"

namespace my_rand {

// [0, 2^64 - 1)
uint64_t rng() {
	static uint64_t x_ =
			uint64_t(chrono::duration_cast<chrono::nanoseconds>(
									 chrono::high_resolution_clock::now().time_since_epoch())
									 .count()) *
			10150724397891781847ULL;
	x_ ^= x_ << 7;
	return x_ ^= x_ >> 9;
}

// [l, r)
int64_t randint(int64_t l, int64_t r) {
	assert(l < r);
	return l + rng() % (r - l);
}

// choose n numbers from [l, r) without overlapping
vector<int64_t> randset(int64_t l, int64_t r, int64_t n) {
	assert(l <= r && n <= r - l);
	unordered_set<int64_t> s;
	for (int64_t i = n; i; --i) {
		int64_t m = randint(l, r + 1 - i);
		if (s.find(m) != s.end()) m = r - i;
		s.insert(m);
	}
	vector<int64_t> ret;
	for (auto& x : s) ret.push_back(x);
	return ret;
}

// [0.0, 1.0)
double rnd() {
	union raw_cast {
		double t;
		uint64_t u;
	};
	constexpr uint64_t p = uint64_t(1023 - 64) << 52;
	return rng() * ((raw_cast*)(&p))->t;
}

template <typename T>
void randshf(vector<T>& v) {
	int n = v.size();
	for (int loop = 0; loop < 2; loop++)
		for (int i = 0; i < n; i++) swap(v[i], v[randint(0, n)]);
}

}  // namespace my_rand

using my_rand::randint;
using my_rand::randset;
using my_rand::randshf;
using my_rand::rnd;
using my_rand::rng;

template <int SZ> struct Sieve {
	int spf[SZ];
	
	Sieve() {
		spf[1] = 1;
		for (int i = 2; i < SZ; i++) 
			spf[i] = i;
		for (int i = 4; i < SZ; i += 2) 
			spf[i] = 2;
		for (int i = 3; i * i < SZ; i++) 
			if (spf[i] == i) 
				for (int j = i * i; j < SZ; j += i) 
					if (spf[j] == j) 
						spf[j] = i;
	}

	std::vector<std::pair<int, int>> factor(int x) {
		std::vector<std::pair<int, int>> ret;
		while (x != 1) {
			if ((int)ret.size() == 0) 
				ret.emplace_back(spf[x], 1);
			else {
				if (ret.back().first == spf[x]) 
					ret.back().second++;
				else 
					ret.emplace_back(spf[x], 1);
			}
			x /= spf[x];
		}
		return ret;
	}
};

vector<int> check3(int n) {
	if (n % 4 == 0 || n % 4 == 1) {
		if (n % 4 == 1) {
			--n;
		}
		vector<int> ret;
		for (int i = 1; i <= n; ++i) {
			if (i == n / 2) {
				continue;
			}
			ret.push_back(i);
		}
		return ret;
	} else {
		if (n % 4 == 3) {
			--n;
		}
		vector<int> ret;
		for (int i = 1; i <= n; ++i) {
			if (i == 2 || i == n / 2) {
				continue;
			}
			ret.push_back(i);
		}
		return ret;
	}

}

vector<int> check2(int n) {
	const int N = 1e6 + 5;
	const long long B = 1e18;
	Sieve<N> sieve;
	vector<long long> random(n + 1);
	vector<long long> hashes(n + 1);
	for (int i = 1; i <= n; ++i) {
		random[i] = randint(B, 9 * B);
		auto f = sieve.factor(i);
		for (auto [p, e] : f) {
			if (e & 1) {
				hashes[i] ^= random[p];
			}
		}
		hashes[i] ^= hashes[i - 1];
	}
	long long all = 0;
	for (long long x : hashes) {
		all ^= x;
	}
	multiset<long long> in;
	for (long long x : hashes) {
		in.insert(x);
	}
	for (int i = 1; i <= n; ++i) {
		in.erase(in.find(hashes[i]));
		if (in.count(hashes[i] ^ all)) {
			for (int j = 1; j <= n; ++j) {
				if (i != j && hashes[j] == (hashes[i] ^ all)) {
					vector<int> ret;
					for (int k = 1; k <= n; ++k) {
						if (k == i || k == j) {
							continue;
						}
						ret.push_back(k);
					}
					return ret;
				}
			}
		}
		in.insert(hashes[i]);
	}
	return {};
}

vector<int> check1(int n) {
	const int N = 1e6 + 5;
	const long long B = 1e18;
	Sieve<N> sieve;
	vector<long long> random(n + 1);
	vector<long long> hashes(n + 1);
	for (int i = 1; i <= n; ++i) {
		random[i] = randint(B, 9 * B);
		auto f = sieve.factor(i);
		for (auto [p, e] : f) {
			if (e & 1) {
				hashes[i] ^= random[p];
			}
		}
		hashes[i] ^= hashes[i - 1];
	}
	long long all = 0;
	for (long long x : hashes) {
		all ^= x;
	}
	for (int i = 1; i <= n; ++i) {
		if (hashes[i] == all) {
			vector<int> ret;
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					continue;
				}
				ret.push_back(j);
			}
			return ret;
		}
	}
	return {};
}

vector<int> check0(int n) {
	const int N = 1e6 + 5;
	const long long B = 1e18;
	Sieve<N> sieve;
	vector<long long> random(n + 1);
	vector<long long> hashes(n + 1);
	for (int i = 1; i <= n; ++i) {
		random[i] = randint(B, 9 * B);
		auto f = sieve.factor(i);
		for (auto [p, e] : f) {
			if (e & 1) {
				hashes[i] ^= random[p];
			}
		}
		hashes[i] ^= hashes[i - 1];
	}
	long long all = 0;
	for (long long x : hashes) {
		all ^= x;
	}
	if (all == 0) {
		vector<int> ret;
		for (int i = 1; i <= n; ++i) {
			ret.push_back(i);
		}
		return ret;
	}
	return {};
}

void finish(vector<int> v) {
	cout << (int)v.size() << '\n';
	for (int x : v) {
		cout << x << ' ';
	}
	cout << '\n';
	exit(0);
}

int main() {
	int n;
	cin >> n;
	auto ans = check0(n);
	if (!ans.empty()) {
		finish(ans);
	} 
	ans = check1(n);
	if (!ans.empty()) {
		finish(ans);
	} 
	ans = check2(n);
	if (!ans.empty()) {
		finish(ans);
	} 
	ans = check3(n);
	if (!ans.empty()) {
		finish(ans);
	} 
	return 0;
}