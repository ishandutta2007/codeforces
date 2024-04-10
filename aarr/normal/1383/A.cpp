#include <bits/stdc++.h>
using namespace std;




int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, ans = 0;
		cin >> n;
		string s, t;
		cin >> s >> t;
		bool b = true;
		for (int i = 0; i < n; i++) {
			if (s[i] > t[i]) {
				b = false;
			}
		}
		if (!b) {
			cout << "-1\n";
			continue;
		}
		
		while (s != t) {
			pair <char, char> p = {'z', 'z'};
			for (int i = 0; i < n; i++) {
				if (s[i] != t[i]) {
					p = min(p, {s[i], t[i]});
				}
			}
			for (int i = 0; i < n; i++) {
				if (s[i] == p.first && t[i] != p.first) {
					s[i] = p.second;
				}
			}
		//	cout << "73 " << p.first << " " << p.second << endl;
			ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}