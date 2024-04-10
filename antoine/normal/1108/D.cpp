#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int ans = 0;

	for (int i = 1; i < n; ++i)
		if (s[i] == s[i - 1]) {
			ans++;
			char c1 = s[i - 1];
			char c2 = i + 1 == n ? 'R' : s[i + 1];
			for (const char c : "RGB")
				if (c != c1 && c != c2) {
					s[i] = c;
					break;
				}
		}

	cout << ans << '\n' << s;
	return 0;
}