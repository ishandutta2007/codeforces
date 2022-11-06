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

int k;

void rec(int now)
{
	if (now == 0) return;
	rec(now / k);
	cout << now % k;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> k;
	forn(i, k)
	{
		forn(j, k)
			if (i && j)
			{
				int now = i * j;
				rec(now);
				cout << " ";
			}
			if (i) cout << endl;
	}

	return 0;
}