
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> cost(1001, 0);
	for(int i = 2; i <= 1000; i++) cost[i] = 1 + cost[__builtin_popcount(i)];
	vector<vector<int>> cnk(1001, vector<int>(1001, 0));
	cnk[0][0] = 1;
	for(int i = 1; i <= 1000; i++)
		for(int j = 0; j <= i; j++)
			cnk[i][j] = (cnk[i - 1][j] + (j ? cnk[i - 1][j - 1] : 0)) % mod;
	string s; int k; cin >> s >> k;
	if(k == 0) return cout << 1, 0;
	int ans = 0;
	for(int one = 1; one <= 1000; one++) {
		if(cost[one] != k - 1) continue;
		int add = 0;
		for(int len = one; len < s.size(); len++)
			add = (add + cnk[len - 1][one - 1]) % mod;
		int ost = one;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '0') continue;
			if(i > 0 && ost >= 0) add = (add + cnk[s.size() - i - 1][ost]) % mod;
			ost--;
		}
		ans = (ans + add) % mod;
	}
	int cnt = 0;
	for(char ch : s) cnt += (ch == '1');
	if(cost[cnt] == k - 1) ans = (ans + 1) % mod;
	if(k == 1) ans = (ans - 1) % mod;
	cout << ans;
}