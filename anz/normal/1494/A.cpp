#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool check(string s)
{
	int cur = 0;
	for (char c : s)
	{
		if (c == '(') cur++;
		else cur--;

		if (cur < 0) return false;
	}

	return cur == 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		string tmp;

		bool ans = false;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'A') c = '(';
			else c = ')';
		}
		if (check(tmp)) ans = true;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'B') c = '(';
			else c = ')';
		}
		if (check(tmp)) ans = true;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'C') c = '(';
			else c = ')';
		}
		if (check(tmp)) ans = true;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'A') c = ')';
			else c = '(';
		}
		if (check(tmp)) ans = true;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'B') c = ')';
			else c = '(';
		}
		if (check(tmp)) ans = true;

		tmp = s;
		for (char& c : tmp)
		{
			if (c == 'C') c = ')';
			else c = '(';
		}
		if (check(tmp)) ans = true;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}