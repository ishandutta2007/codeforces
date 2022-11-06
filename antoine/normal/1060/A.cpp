#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	const int m = count(s.begin(), s.end(), '8');

	int ans = min(m, n / 11);
	cout << ans << '\n';
	return 0;
}