#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	int i = 0, j = n - 1;
	string ans = "";
	while(j - i > 1) {
		if(s[i] == s[j]) {
			ans += s[i];
			i++;
			j--;
		} else if(s[i] == s[j - 1]) {
			ans += s[i];
			i++;
			j -= 2;
		} else if(s[i + 1] == s[j]) {
			ans += s[i + 1];
			i += 2;
			j--;
		} else {
			ans += s[i + 1];
			i += 2;
			j -= 2;
		}
	}
	//cout << i << ' ' << j << endl;
	if(j - i == 1 && s[i] != s[j]) {
		j--;
	}
	bool odd = (j - i) % 2;
	if(j - i >= 0) {
		ans += s[i];
	}
	if(odd) {
		ans = ans + string(ans.rbegin(), ans.rend());
	} else {
		ans = ans + string(ans.rbegin() + 1, ans.rend());
	}
	cout << ans << endl;
	return 0;
}