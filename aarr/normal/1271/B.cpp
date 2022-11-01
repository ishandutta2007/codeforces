#include <iostream>
#include <vector>
using namespace std;


bool b[205];
vector <int> ans1;


int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			b[i] = true;
		}
	}
	for (int i = 1; i < n - 1; i++) {
		if (b[i] != b[i - 1]) {
			ans1.push_back(i);
			b[i] ^= 1;
			b[i + 1] ^= 1;
		}
	} 
	bool a = true;
	for (int i = 1; i < n; i++) {
		if (b[i] != b[0]) {
			a = false;
		}
	}
	if (a) {
		cout << ans1.size() << endl;
		for (auto x : ans1) {
			cout << x + 1 << " ";
		}
	}
	else {

		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				b[i] = true;
			}
			else {
				b[i] = false;
			}
		}
		b[0] ^= 1;
		b[1] ^= 1;
		ans1.clear();
		ans1.push_back(0);
		for (int i = 1; i < n - 1; i++) {
			if (b[i] != b[i - 1]) {
				ans1.push_back(i);
				b[i] ^= 1;
				b[i + 1] ^= 1;
			}
		} 
		bool a = true;
		for (int i = 1; i < n; i++) {
			if (b[i] != b[0]) {
				a = false;
			}
		}
		if (a) {
			cout << ans1.size() << endl;
			for (auto x : ans1) {
				cout << x + 1 << " ";
			}
		}	
		else {
			cout << -1 << endl;
		}	
	}
	return 0;
}