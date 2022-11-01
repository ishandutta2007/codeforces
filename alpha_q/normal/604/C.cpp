#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; string s;
	cin >> n >> s;
	int ret = 1;
	for (int i = 1; i < n; i++) ret += s[i] != s[i - 1];
	cout << min(n, ret + 2) << endl;
	return 0;
}