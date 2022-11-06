#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define seta(a, b) memset(a, b, sizeof(a))

int n, num;
char s[20];
vector <char> ans[1000002];

void next()
{
	vector <char> tmp;
	for (int i = ans[num].size() - 1; i >=0; i--)
		if (ans[num][i] != 'Z')
		{
			num++;
			ans[num] = ans[num - 1];
			ans[num][i]++;
			for (int j = i + 1; j < ans[num].size(); j++)
				ans[num][j] = 'A';
			return;
		}
	
	tmp.clear();
	forn(i, ans[num].size() + 1)
		tmp.push_back('A');
	num++;
	ans[num] = tmp;
}

int get(int l, int r, bool type)
{
	if (!type)
	{
		int res = 0;
		for (int i = l; i <= r; i++)
			res = res * 10 + s[i] - '0';
		return res;
	}
	
	int ll = 0, rr = 1000000;
	vector <char> tmp;
	tmp.clear();
	for (int i = l; i <= r; i++)
		tmp.push_back(s[i]);
	while (rr > ll + 1)
	{
		int m = (ll + rr) / 2;
		if ((r - l + 1 < ans[m].size()) || ((r - l + 1 == ans[m].size()) && (ans[m] > tmp))) rr = m;
		else ll = m;
	}
	if (ans[ll] == tmp) return ll;
	else return rr;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	ans[1].clear();
	ans[1].push_back('A');
	num = 1;
	while (num < 1000000)
	{
		next();
/*		cout << num << " ";
		forn(i, ans[num].size())
			cout << ans[num][i];
		cout << endl;*/
	}
	
	cin >> n;
	forn(i, n)
	{
		scanf("%s", s);
		int smin = 1000, smax = 0, dmin = 1000, dmax = 0;
		forn(j, strlen(s))
			if ('A' <= s[j] && s[j] <= 'Z')
			{
				smin = min(smin, j);
				smax = max(smax, j);
			}
			else
			{
				dmin = min(dmin, j);
				dmax = max(dmax, j);
			}
			
		if (smax < dmin)
		{
			int x = get(smin, smax, true);
			int y = get(dmin, dmax, false);
			cout << "R" << y << "C" << x << endl;
		}
		else
		{
			int x = get(dmin, smax - 1, false);
			int y = get(smax + 1, dmax, false);
			forn(j, ans[y].size())
				cout << ans[y][j];
			cout << x << endl;
		}
	}
	
	return 0;
}