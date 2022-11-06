#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int diff = 0;

	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		int x = s[i] == '?' ? 9 : 2 * int(s[i] - '0');
		diff += i < n / 2 ? -x : x;
	}
	cout << (diff ? "Monocarp" : "Bicarp");
	return 0;
}