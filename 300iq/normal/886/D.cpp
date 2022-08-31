#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector <int> a(26, -1);
	vector <int> b(26, -1);
	vector <int> cnt(26);
	for (int i = 0; i < n; i++)
	{
		vector <bool> kek(26);
		string s;
		cin >> s;
		for (auto &c : s)
		{
			c -= 'a';
			cnt[c]++;
			if (kek[c])
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				kek[c] = true;
			}
		}
		for (int i = 0; i + 1 < (int) s.size(); i++)
		{
			if (a[s[i]] != -1 && a[s[i]] != s[i + 1])
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				if (b[s[i + 1]] != -1 && b[s[i + 1]] != s[i])
				{
					cout << "NO\n";
					return 0;
				}
				a[s[i]] = s[i + 1];
				b[s[i + 1]] = s[i];
			}
		}
	}
	vector <string> res;
	vector <bool> vis(26);
	for (int i = 0; i < 26; i++)
	{
		if (b[i] == -1 && cnt[i])
		{
			string s = "";
			int x = i;
			while (x != -1)
			{
				vis[x] = 1;
				s += (x + 'a');
				x = a[x];
			}
			res.push_back(s);
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (!vis[i] && cnt[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	sort(res.begin(), res.end(), [] (string a, string b)
	{
		return a + b < b + a;
	});
	for (auto c : res) cout << c;
	cout << '\n';
}