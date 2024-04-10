#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
		cin >> words[i];
	vector<vector<int>> pr(n);
	int base = 200, mod = 1000000007;
	for (int i = 0; i < n; ++i) {
		pr[i].push_back(0);
		for (int j = 0; j < words[i].size(); ++j)
			pr[i].push_back((pr[i][j] * base + words[i][j]) % mod);
	}
	string ans = words[0];
	vector<int> pr_ans = pr[0];
	vector<int> st(1000001);
	st[0] = 1;
	for (int i = 1; i < st.size(); ++i)
		st[i] = (st[i-1] * base) % mod;
	for (int i = 1; i < n; ++i) {
		int d = 0;
		for (int j = 0; j < min(words[i].size(), ans.size())+1; ++j) {
			int hash1 = (pr_ans.back() - (pr_ans[pr_ans.size() - j - 1] * st[j]) % mod) % mod, hash2 = pr[i][j];
			if (hash1 < 0)
				hash1 += mod;
			if (hash1 == hash2)
				d = j;
		}
		for (int j = d; j < words[i].size(); ++j) {
			pr_ans.push_back((pr_ans.back() * base + words[i][j]) % mod);
			ans += words[i][j];
		}
	}
	cout << ans;
	return 0;
}