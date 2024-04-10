#include <iostream>
using namespace std;


int cnt[30];
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool b = true;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
		if (cnt[s[i] - 'a'] > k) {
			b = false;
		}
	}
	if (b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}