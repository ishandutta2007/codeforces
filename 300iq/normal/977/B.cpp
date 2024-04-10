#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	map <pair <char, char>, int> cnt;
	for (int i = 1; i < (int) s.size(); i++)
	{
		 cnt[{s[i - 1], s[i]}]++;
	}
	pair <pair <char, char>, int> ans;
	for (auto c : cnt)
	{
		 if (c.second > ans.second) ans = c;
	}
	cout << ans.first.first << ans.first.second << '\n';
}