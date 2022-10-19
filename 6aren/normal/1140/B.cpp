#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int ntest, n;
	cin >> ntest;
	while (ntest--) {
		cin >> n;
		cin >> s;
		int left = 0, right = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '<') {
				left++;
			} else break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '>') {
				right++;
			} else break;
		}
		cout << min(left, right) << endl;
	}
	return 0;
}