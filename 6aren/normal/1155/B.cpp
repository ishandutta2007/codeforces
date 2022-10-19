#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	cin >> s;
	n = (n - 11) / 2;
	int cur = n, cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (cur == 0 && s[i] != '8') break;
		if (s[i] == '8') cnt++;
		else {
			cur--;
		}
	}
	if (cnt > n) cout << "YES";
	else cout << "NO";
	return 0;
}