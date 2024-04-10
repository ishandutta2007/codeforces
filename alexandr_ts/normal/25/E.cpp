#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <typeinfo>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <string_view>
#include <exception>

#define debug(x) cout << #x << " is " << (x) << endl;

using namespace std;

using ll = long long;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;

string s[3];
ll hashes[3][N];
ll pw[N];

void prec() {
	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = pw[i - 1] * P % MOD;	
	}
}

void build_hash(const string& s, ll* hashes) {
	hashes[0] = 0;	
	for (int i = 0; i < s.size(); ++i) {
		hashes[i + 1] = (hashes[i] * P + (s[i] - 'a' + 1)) % MOD;	
	}
}

ll get_hash(ll* hashes, int l, int r) {
	return ((hashes[r + 1] - hashes[l] * pw[r - l + 1]) % MOD + MOD) % MOD;
}

void solve() {
	prec();
	for (int i = 0; i < 3; ++i) {
		cin >> s[i];	
		build_hash(s[i], hashes[i]);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) continue;
			if (s[i].size() < s[j].size()) continue;
			for (int k = 0; k <= s[i].size() - s[j].size(); k++) {
				if (get_hash(hashes[i], k, k + s[j].size() - 1) == get_hash(hashes[j], 0, s[j].size() - 1)) {
					s[j] = "";	
				}
			}
		}	
	}
	vector<int>v{0, 1, 2};
	int ans = s[0].size() + s[1].size() + s[2].size();
	do {
		int i1 = v[0], i2 = v[1], i3 = v[2];
		int max1 = 0;
		for (int i = 1; i <= min(s[i1].size(), s[i2].size()); ++i) {
			if (get_hash(hashes[i1], (int)s[i1].size() - i, (int)s[i1].size() - 1) ==
				get_hash(hashes[i2], 0, i - 1)) {
				max1 = max(max1, i);	
			} 
		}		
		int max2 = 0;
		for (int i = 1; i <= min(s[i2].size(), s[i3].size()); ++i) {
			if (get_hash(hashes[i2], (int)s[i2].size() - i, (int)s[i2].size() - 1) ==
				get_hash(hashes[i3], 0, i - 1)) {
				max2 = max(max2, i);	
			} 
		}
		ans = min(ans, (int)(s[0].size() + s[1].size() + s[2].size() - max1 - max2));
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}