#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

int n;
map<string, int> G[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cout << "? " << 1 << " " << n << endl;
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		G[s.length()][s]++;
	}
	
	if (n > 1) {
		cout << "? " << 2 << " " << n << endl;
		for (int i = 0; i < n * (n - 1) / 2; i++) {
			string s;
			cin >> s;
			sort(s.begin(), s.end());
			G[s.length()][s]--;
		}
	}

	vector<string> S (n + 1);
	for (int i = 1; i <= n; i++) {
		for (auto& t : G[i]) {
			if (t.second == 1) {
				S[i] = t.first;
			}
		}
	}

	string ans = "";
	for (int i = 1; i <= n; i++) {
		vector<int> cnt (26, 0);
		for (auto c : S[i])
			cnt[c - 'a']++;
		for (auto c : ans)
			cnt[c - 'a']--;
		int x = 0;
		while (!cnt[x])
			x++;
		ans += (char) ('a' + x);
	}
	cout << "! " << ans << endl;
	return 0;
}