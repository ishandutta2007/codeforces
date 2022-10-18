#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

vector<int> ws(string s) {
	char last = 'o';
	vector<int> ans = {0};
	for(auto c: s) {
		ans.push_back(ans.back() + (c == 'v' && last == 'v'));
		last = c;
	}
	return ans;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	auto A = ws(s);
	auto B = ws(string(s.rbegin(), s.rend()));
	int ans = 0;
	int n = s.size();
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] == 'o') {
			ans += A[i] * B[n - i];
		}
	}
	cout << ans << endl;
	return 0;
}