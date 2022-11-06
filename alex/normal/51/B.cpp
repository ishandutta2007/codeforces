#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

vector <int> ans;

int table();

string get_word()
{
	int now = 0;
	char ch = ' ', s[10];
	while (ch <= ' ') scanf("%c", &ch);
	while (ch != '>')
	{
		s[now++] = ch;
		ch = ' ';
		while (ch <= ' ') scanf("%c", &ch);
	}
	s[now++] = ch;
	s[now] = '\0';
	string res;
	res = s;
	return res;
}

int cell()
{
	int res = 0;
	string now = get_word();
	while (now != "</td>")
	{
		if (now == "<table>")
		{
			int tmp= table();
			ans.pb(tmp);
			res++;
		}
		now = get_word();
	}
	if (!res) res = 1;
	return res;
}

int row()
{
	int res = 0;
	string now = get_word();
	while (now != "</tr>")
	{
		if (now == "<td>") res += cell();
		now = get_word();
	}
	return res;
}

int table()
{
	int res = 0;
	string now = get_word();
	while (now != "</table>")
	{
		if (now == "<tr>") res += row();
		now = get_word();
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ans.pb(table());
	sort(all(ans));
	forn(i, ans.size())
		printf("%d ", ans[i]);

	return 0;
}