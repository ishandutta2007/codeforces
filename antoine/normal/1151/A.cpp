#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int g(int x) {
	return (x % 26 + 26) % 26;
}
int f(int x) {
	return min(g(x), g(-x));
}
int f(string s, string t) {
	int res = 0;
	for (int i = 0; i < 4; ++i)
		res += f(s[i] - t[i]);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int ans = 1 << 30;
	for (int i = 0; i + 4 <= n; ++i)
		ans = min(ans, f(s.substr(i, 4), "ACTG"));
	cout << ans;
	return 0;
}