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

int a, b;
long long n;

bool lose[100010][32];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> a >> b >> n;
	forn(i, 100000)
		if (i > 1)
	{
		long long now = 1;
		forn(j, 30)
		{
			now *= i;
			if (now >= n)
			{
				now = n;
				lose[i][j + 1] = false;
			}
			else lose[i][j + 1] = true;
		}
	}

	for (int i = 99998; i > 1; i--)
		for (int j = 29; j > 1; j--)
			if (lose[i][j] && (lose[i][j + 1] || lose[i + 1][j])) lose[i][j] = false;

	if (n & 1) lose[99997][1] = true;
	else lose[99998][1] = true;

	for (int i = 99998; i > 1; i--)
		if (lose[i][1] && (lose[i + 1][1] || lose[i][2])) lose[i][1] = false;

	if (a > 1 && b >= 1)
	{
		if (lose[a][b]) cout << "Stas" << endl;
		else cout << "Masha" << endl;
		return 0;
	}

	for (int i = b; i <= 30; i++)
		if (lose[2][i])
		{
			if ((i - b) & 1) cout << "Stas" << endl;
			else cout << "Masha" << endl;
			return 0;
		}
	cout << "Missing" << endl;

	return 0;
}