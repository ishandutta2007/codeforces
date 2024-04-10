#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for(int i = 0, j = 0; i < n; i += ++j)
		cout << s[i];
	return 0;
}