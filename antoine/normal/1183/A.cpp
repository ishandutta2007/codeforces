#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f(int x) {
	string s = to_string(x);
	int sum = 0;
	for (char c : s)
		sum += (c - '0');
	return sum % 4 == 0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int x;
	cin >> x;
	while (!f(x))
		++x;
	cout << x;
	return 0;
}