#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	int cnts[2] = { 0, 0 };

	for (const char c : s) {
		int &cnt = cnts[c - '0'];
		if(c == '0') {
			cout << (cnt * 2 + 1) << ' ' << 3 << '\n';
			(++cnt) %= 2;
		} else {
			cout << (cnt + 1) << ' ' << 1 << '\n';
			(++cnt) %= 4;
		}
	}
	return 0;
}