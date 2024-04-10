#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	string t = s;

	string rgb = "RGB";
	sort(rgb.begin(), rgb.end());
	pair<int, string> ans = { n + 1, "" };
	do {
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += s[i] != (t[i] = rgb[i % 3]);
		ans = min(ans, { cnt, t });
	} while (next_permutation(rgb.begin(), rgb.end()));
	cout << ans.first << '\n' << ans.second;
	return 0;
}