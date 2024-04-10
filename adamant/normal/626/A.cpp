#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			string t = s.substr(i, j - i + 1);
			ans += count(begin(t), end(t), 'U') == count(begin(t), end(t), 'D') && count(begin(t), end(t), 'L') == count(begin(t), end(t), 'R');
		}
	cout << ans << "\n";
	return 0;
}