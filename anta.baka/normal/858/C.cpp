#include <bits/stdc++.h>

using namespace std;

string s;
int n;

bool sogl(char x) {
	return x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u';
}

int dp[3000], opt[3000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		dp[i] = i + 1;
		opt[i] = i;
		for(int j = i; j >= 0; j--) {
			if(i - j + 1 >= 3 && sogl(s[j]) && sogl(s[j + 1]) && sogl(s[j + 2]) && (s[j] != s[j + 1] || s[j] != s[j + 2] || s[j + 1] != s[j + 2]))
				break;
			if((j != 0 ? dp[j - 1] : 0) + 1 < dp[i]) {
				dp[i] = (j != 0 ? dp[j - 1] : 0) + 1;
				opt[i] = j;
			}
		}
	}
	vector<char> ans;
	int v = n - 1;
	while(v != -1) {
		int u = opt[v];
		for(int i = v; i >= u; i--)
			ans.push_back(s[i]);
		ans.push_back(' ');
		v = u - 1;
	}
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	for(char x : ans) cout << x;
}