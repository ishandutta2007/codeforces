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

int const p = 1000000007;
int n;

int64 pow(int64 n)
{
	int64 res = 1, tmp = n;
	forn(i, 31)
	{
		if (((p - 2) >> i) & 1)
			res = (res * tmp) % p;
		tmp = (tmp * tmp) % p;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;

	int64 now = 1;
	forn(i, n)
		now = (now * (n + i)) % p;
	forn(i, n)
		now = (now * pow(i + 1)) % p;

	cout << (p + 2 * now - n) % p << endl;

	return 0;
}