#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a + mod - b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

const int maxn = 1e5 + 42;


string fast(string s) {
	size_t cnt[26];
	memset(cnt, 0, sizeof cnt);
	for(auto c: s) {
		cnt[c - 'a']++;
	}
	string ans;
	vector<int> chars;
	for(int i = 0; i < 26; i++) {
		if(cnt[i] == 1 && ans.empty()) {
			ans += char('a' + i);
			cnt[i]--;
		}
		if(cnt[i]) {
			chars.push_back(i);
		}
	}
	if(!ans.empty()) {
		for(size_t i = 0; i < chars.size(); i++) {
			ans += string(cnt[chars[i]], 'a' + chars[i]);
			cnt[chars[i]] = 0;
		}
	} else if(chars.size() > 1) {
		ans += 'a' + chars[0];
		cnt[chars[0]] -= 1;
		if(cnt[chars[0]] * 2 <= s.size()) {
			ans += 'a' + chars[0];
			cnt[chars[0]] -= 1;
		} else {
			if(chars.size() > 2) {
				ans += 'a' + chars[1];
				cnt[chars[1]] -= 1;
				ans += string(cnt[chars[0]], 'a' + chars[0]);
				cnt[chars[0]] = 0;
				ans += 'a' + chars[2];
				cnt[chars[2]] -= 1;
			} else {
				ans += string(cnt[chars[1]], 'a' + chars[1]);
				ans += string(cnt[chars[0]], 'a' + chars[0]);
				cnt[chars[0]] = cnt[chars[1]] = 0;
			}
		}		
		for(size_t i = 1; i < chars.size(); i++) {
			for(size_t j = 0; j < cnt[chars[i]]; j++) {
				ans += 'a' + chars[i];
				if(cnt[chars[0]]) {
					ans += 'a' + chars[0];
					cnt[chars[0]]--;
				}
			}
		}
	}
	if(!chars.empty()) {
		ans += string(cnt[chars[0]], 'a' + chars[0]);
	}
	return ans;
}

string slow(string s) {
	int bst = s.size() + 10;
	string ans;
	sort(all(s));
	do {
		int cur = 0;
		for(int i = 1; i < s.size(); i++) {
			int j = 0;
			while(i + j < s.size() && s[i + j] == s[j]) {
				j++;
			}
			cur = max(cur, j);
		}
		if(cur < bst || (cur == bst && s < ans)) {
			bst = cur;
			ans = s;
		}
	} while(next_permutation(all(s)));
	return ans;
}

void solve() {
	string s;
	cin >> s;
	cout << fast(s) << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
	for(int z = 0; z < 1000000; z++) {
		string s;
		int ln = rand() % 8 + 1;
		for(int k = 0; k < ln; k++) {
			s += 'd' + rand() % 1;
		}
		cout << s << ' ' << fast(s) << ' ' << slow(s) << endl;
		assert(fast(s) == slow(s));
	}
}