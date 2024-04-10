#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	cin >> s;
	int flag = -1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1]) flag = i + 1;
	}
	if (flag == -1) cout << "NO";
	else {
		cout << "YES" << endl;
		cout << flag << ' ' << flag + 1;
	}
	return 0;
}