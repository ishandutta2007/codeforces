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
	for (int i = 0; i + 1 < n; ++i)
		if (s[i] != s[i + 1]) {
			cout << "YES\n" << s[i] << s[i + 1];
			return 0;
		}
	cout << "NO\n";
	return 0;
}