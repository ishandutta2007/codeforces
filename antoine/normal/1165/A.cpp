#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	s = s.substr(n - x);

	int ans = 0;
	for (int i = 0; i < (int) s.size(); ++i)
		ans += s[i] != (i == (int)s.size() - 1 - y?'1':'0');
	cout << ans;
	return 0;
}