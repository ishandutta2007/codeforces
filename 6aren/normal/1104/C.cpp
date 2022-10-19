#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	string s;
	cin >> s;
	int cnt1 = 1, cnt2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			cout << cnt1 << " " << 1 << endl;
			cnt1 = (cnt1 + 2) % 4;
		} else {
			cout << cnt2 + 1 << " " << 2 << endl;
			cnt2 = (cnt2 + 1) % 4;
		}
	}
	return 0;
}