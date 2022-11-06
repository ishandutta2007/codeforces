#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char mp[256];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for (char c = '1'; c <= '9'; ++c)
		cin >> mp[c];

	int i = 0;
	while (i < n && mp[s[i]] <= s[i])
		++i;
	while (i < n && mp[s[i]] >= s[i]) {
		s[i] = mp[s[i]];
		++i;
	}
	cout << s;
	return 0;
}