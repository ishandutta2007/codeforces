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

int const NMAX = 5;
int n, a[NMAX];
char s[10];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	forn(i, 5)
		cin >> a[i];
	cin >> n;
	forn(i, n)
	{
		int now;
		cin >> s;
		if (strcmp(s, "S") == 0) now = 0;
		if (strcmp(s, "M") == 0) now = 1;
		if (strcmp(s, "L") == 0) now = 2;
		if (strcmp(s, "XL") == 0) now = 3;
		if (strcmp(s, "XXL") == 0) now = 4;
		int best  = 10, tmp = -1;
		forn(j, 5)
			if (a[j] > 0 && abs(j - now) <= best)
			{
				best =  abs(j - now);
				tmp = j;
			}
		a[tmp]--;
		if (tmp == 0) cout << "S" << endl;
		if (tmp == 1) cout << "M" << endl;
		if (tmp == 2) cout << "L" << endl;
		if (tmp == 3) cout << "XL" << endl;
		if (tmp == 4) cout << "XXL" << endl;
	}

	return 0;
}