#include <iostream>
#include <set>
using namespace std;

set <int> d;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		while (d.size()) {
			d.erase(d.begin());
		}
		int ans = 0;
		for (int i = 0; i + 2 < s.size(); i++) {
			if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
				ans++;
				d.insert(i + 1);
			}
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
				ans++;
				d.insert(i + 1);
			}
		}
		for (int i = 0; i + 4 < s.size(); i++) {
			if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' & s[i + 4] == 'e') {
				ans--;
				d.erase(i + 1);
				d.erase(i + 3);
				d.insert(i + 2);
			}
		}
		cout << ans << endl;
		for (auto x : d) {
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}