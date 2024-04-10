#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bal = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		bal += s[i] == '(' ? 1 : -1;
		if(bal < 0) {
			bal++;
			cnt++;
		}
	}
	if(bal == 0 && cnt == 0 || bal == 1 && cnt == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
    return 0;
}