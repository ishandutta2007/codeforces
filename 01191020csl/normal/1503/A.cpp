#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		bool res = 1;
		string ans1, ans2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1') ++cnt;
		if (cnt & 1) {
			puts("NO");
			continue;
		}
		int c1 = 0, c2 = 0;
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (c1) ans1.push_back(')'), ans2.push_back('('), ++t2, --t1;
				else ans1.push_back('('), ans2.push_back(')'), ++t1, --t2;
				c1 ^= 1;
			}
			if (s[i] == '1') {
				if (c2 * 2 == cnt) ans1.push_back(')'), ans2.push_back(')'), --t1, --t2;
				else ans1.push_back('('), ans2.push_back('('), ++t1, ++t2, ++c2;
			}
			if (t1 < 0 || t2 < 0) {
				puts("NO"), res = 0;
				break;
			}
		}
		if (!res) continue;
		puts("YES");
		cout << ans1 << endl << ans2 << endl;
	}
}