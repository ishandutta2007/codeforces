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

const string task = "";

char s[100000];
int a, l, zn;
long long d[1010][1010];
vector <int> q[2];

void get()
{
	int k = 0;
	if (s[l] >= '0' && s[l] <= '9')
	{
		while (s[l] != '*')
		{
			k = k * 10 + s[l] - '0';
			l++;
		}
		l++;
	}
	else k = 1;
	k *= zn;
	int tp;

	if (s[l] == 'a') tp = 0;
	else tp = 1;
	l += 3;

	q[tp].pb(k);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> a;
	scanf("%s", s);
	s[strlen(s) + 1] = '\0';
	s[strlen(s)] = '@';
	l = 0, zn = 1;
	
	while (true)
	{
		get();
		if (s[l] == '@') break;
		if (s[l] == '+') zn = 1;
		else zn = -1;
		l++;
	}

	sort(all(q[0]));
	sort(all(q[1]));

	forn(i, q[0].size() + 1)
		forn(j, q[1].size() + 1)
			d[i][j] = -inf64;
	d[0][0] = 0;

	forn(i, q[0].size() + 1)
		forn(j, q[1].size() + 1)
			if (d[i][j] == -inf64)
			{
				if (i > 0) d[i][j] = max(d[i][j], d[i - 1][j] + q[0][i - 1] * (a + i + j - 1));
				if (j > 0) d[i][j] = max(d[i][j], d[i][j - 1] + q[1][j - 1] * (a + i + j));
			}

	cout << d[q[0].size()][q[1].size()] << endl;

	return 0;
}