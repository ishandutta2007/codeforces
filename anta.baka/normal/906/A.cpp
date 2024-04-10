#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<bool> may(26, true);
	int ans = 0;
	bool go = false;
	for(int i = 0; i < n - 1; i++) {
		char ch; string s; cin >> ch >> s;
		if(ch == '.') {
			for(char x : s) may[x - 'a'] = false;
		} else if(ch == '!') {
			vector<bool> was(26, false);
			for(char x : s) was[x - 'a'] = true;
			for(int x = 0; x < 26; x++)
				if(!was[x])
					may[x] = false;
			if(go) ans++;
		} else {
			may[s[0] - 'a'] = false;
			if(go) ans++;
		}
		int cnt = 0;
		for(int ch = 0; ch < 26; ch++)
			cnt += may[ch];
		if(cnt == 1)
			go = true;
	}
	cout << ans;
}