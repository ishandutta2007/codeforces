#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string pname = "e";

const int NMAX = 205;
const int SMAX = 1001000;

int n, num, V, l, ans;
char s[SMAX], tmp[3100];
string str[NMAX], name[SMAX];
vector <int> nxt[SMAX], st;

void dfs(int v, int now)
{
	if (now == num) now--;
	if (name[v] == str[now]) now++;
	if (now == num) ans++;
	forn(i, nxt[v].size())
		dfs(nxt[v][i], now);
}

int next_teg(string &name, int &type)
{
	if (s[l] == '\0') return 0;
	l++;
	type = 1;
	if (s[l] == '/') type = -1, l++;
	name = "";
	while (s[l] >= 'a' && s[l] <= 'z')
	{
		name += s[l];
		l++;
	}
	if (s[l] == '/') type = 0, l++;
	l++;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((pname + ".in").data(), "r", stdin);
	freopen((pname + ".out").data(), "w", stdout);
#endif

	gets(s);
	cin >> n;
	gets(tmp);

	V = 0;
	name[V++] = "@";
	st.pb(0);
	l = 0;
	int type;
	while (next_teg(name[V], type))
	{
		if (type == 0)
		{
			nxt[st[st.size() - 1]].pb(V);
			V++;
		}
		if (type == 1)
		{
			nxt[st[st.size() - 1]].pb(V);
			st.pb(V++);
		}
		if (type == -1)
			st.pop_back();
	}

	forn(i, n)
	{
		ans = 0;
		gets(tmp);
		num = 0;
		int j = 0;
		while (1)
		{
			str[num] = "";
			while (tmp[j] > ' ')
			{
				str[num] += tmp[j];
				j++;
			}
			num++;
			if (tmp[j] == '\0') break;
			j++;
		}
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}