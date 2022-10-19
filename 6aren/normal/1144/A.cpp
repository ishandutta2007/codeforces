#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	while (n--) {
		char s[200];
		cin >> s;
		sort(s, s + strlen(s));
		bool flag = 1;
		for (int i = 1; i < strlen(s); i++) {
			if (s[i] - 1 != s[i - 1]) flag = 0;
		}
		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}