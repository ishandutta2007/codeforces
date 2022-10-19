#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int f[200010];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 200005; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	}
	int cnt = 1;
	int res = 1;
	if (s[0] == 'm' || s[0] == 'w') res = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'm' || s[i] == 'w') res = 0;
		if (s[i] != s[i - 1]) {
			if (s[i - 1] == 'n' || s[i - 1] == 'u') {
				res = (1LL * res * f[cnt]) % MOD;
			}
			cnt = 1;
		} else {
			cnt++;
		}
	}
	if (s[s.size() - 1] == 'n' || s[s.size() - 1] == 'u') {
		res = (1LL * res * f[cnt]) % MOD;
	}		
	cout << res;
	return 0;
}