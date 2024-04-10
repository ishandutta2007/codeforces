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
#include <cassert>
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
#define sqr(x) ((int64) x) * (x)

const string name = "b";

bool may[1000];
int used[1000];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	string s, ss;
	char buf[1000];
	gets(buf);
	s = buf;
	while (s.find("  ") >= 0 && s.find("  ") < s.size())
		s = s.substr(0, s.find("  ")) + s.substr(s.find("  ") + 1, (int) s.size());
	while (s.find(" ,") >= 0 && s.find(" ,") < s.size())
		s = s.substr(0, s.find(" ,")) + s.substr(s.find(" ,") + 1, (int) s.size());
	while (s.find(". ") >= 0 && s.find(". ") < s.size())
		s = s.substr(0, s.find(". ") + 1) + s.substr(s.find(". ") + 2, (int) s.size());

	ss = "";
	forn(i, s.size())
		if (s[i] == ',' && i != (int) s.size() - 1 && s[i + 1] != ' ')
			ss += ", ";
		else ss += s[i];
	s = ss;

	ss = "";
	seta(may, 1);
	seta(used, 0);
	forn(i, s.size() - 2)
		if (!used[i] && s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
			may[i] = may[i + 1] = false;
			used[i] = used[i + 1] = used[i + 2] = 1;
		}
	forn(i, s.size())
		if (i < (int) s.size() - 3 && may[i] && s[i] != ' ' && s[i + 1] == '.' && s[i + 2] == '.' && s[i + 3] == '.')
		{
			ss += s[i];
			ss += " ";
		}
		else ss += s[i];
	cout << ss << endl;

	return 0;
}