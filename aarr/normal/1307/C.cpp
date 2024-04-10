#include <bits/stdc++.h>
using namespace std;

const int M = 30;


long long cnt[M][M];
long long c[M];

int main() {
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int x = s[i] - 'a';
		for (int j = 0; j < 26; j++) {
			cnt[j][x] += c[j];
		}
		c[x]++;
	} 
	long long ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, c[i]);
		for (int j = 0; j < 26; j++) {
			ans = max(ans, cnt[i][j]);
		}
	}
	cout << ans;
	return 0;
}