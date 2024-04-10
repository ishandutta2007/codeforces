#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = n - 1; i; i--) {
		int l1 = s[i - 1].length();
		int l2 = s[i].length();
		for(int j = 0; j < min(l1, l2); j++) {
			if(s[i - 1][j] < s[i][j]) {
				break;
			}
			if(s[i - 1][j] > s[i][j]) {
				s[i - 1].erase(j);
				break;
			}
		}
		if(s[i - 1] > s[i]) {
			s[i - 1].erase(s[i].length());
		}
	}
	for(int i = 0; i < n; i++) {
		cout << s[i] << "\n";
	}
}