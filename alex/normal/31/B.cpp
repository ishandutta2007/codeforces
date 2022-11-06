#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int n;
char s[10000];
vector <string> ans;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s;
	n = strlen(s);

	if (s[0] == '@' || s[n - 1] == '@')
	{
		cout << "No solution" << endl;
		return 0;
	}
	bool w = false;
	forn(i, n)
		if (s[i] == '@') w = true;
	if (!w)
	{
		cout << "No solution" << endl;
		return 0;
	}

	ans.clear();
	forn(i, n)
	{
		if (i == 0 || (i > 1 && s[i - 2] == '@'))
			ans.push_back("");
		ans[ans.size() - 1] += s[i];
	}

	w = false;
	forn(i, ans[ans.size() - 1].size())
		if (ans[ans.size() - 1][i] == '@') w = true;
	if (!w)
	{
		ans[ans.size() - 2] += ans[ans.size() - 1];
		ans.pop_back();
	}

	forn(i, ans.size())
	{
		int cnt = 0;
		forn(j, ans[i].size())
			if (ans[i][j] == '@') cnt++;
		if (cnt > 1) 
		{
			cout << "No solution" << endl;
			return 0;
		}
		if (ans[i][0] == '@' || ans[i][ans[i].size() - 1] == '@')
		{
			cout << "No solution" << endl;
			return 0;
		}
	}

	forn(i, ans.size())
	{
		if (i) cout << ',';
		cout << ans[i];
	}
	cout << endl;

	return 0;
}