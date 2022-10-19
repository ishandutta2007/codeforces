#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ldb;

int to_int(string s) {
	reverse(s.begin(), s.end());
	int n = 0;
	for (char c : s) {
		n *= 2;
		n += c - '0';
	}
	return n;
}

struct Stack {
	char c;
	Stack *prev;

	Stack(char c) : c(c) {
		prev = NULL;
	}
};

Stack* pb(Stack *s, char c) {
	if (s == NULL)
		return s;
	Stack *s2 = new Stack(c);
	s2->prev = s;
	return s2;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<string> nums_str = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<int> nums;
	for (int i = 0; i < 10; i++) {
		nums.push_back(to_int(nums_str[i]));
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i] = to_int(s);
	}
	vector<pair<Stack*, int>> dp;
	for (int i = 9; i >= 0; i--) {
		if ((arr[0] & nums[i]) == arr[0]) {
			int cnt = __builtin_popcount(arr[0] ^ nums[i]);
			if (cnt <= k) {
				dp.push_back({new Stack(i + '0'), cnt});
			}
		}
	}
	for (int i = 1; i < n; i++) {
		vector<pair<Stack*, int>> dp2;
		for (auto &el : dp) {
			for (int x = 9; x >= 0; x--) {
				if ((arr[i] & nums[x]) == arr[i]) {
					int cnt = __builtin_popcount(arr[i] ^ nums[x]);
					if (cnt + el.second <= k) {
						dp2.push_back({pb(el.first, x + '0'), cnt + el.second});
					}
				}
			}
		}
		unordered_set<int> used;
		dp.clear();
		for (auto &el : dp2) {
			if (used.count(el.second)) {
				continue;
			}
			used.insert(el.second);
			dp.push_back(el);
		}
	}
	for (auto &el : dp) {
		if (el.second == k) {
			string s;
			auto n = el.first;
			while (n) {
				s.push_back(n->c);
				n = n->prev;
			}
			reverse(s.begin(), s.end());
			cout << s << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/