#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second

int n;
char a[1000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> a;
	int best = -1;
	forn(i, n)
		for (int j = i - 1; j >= 0; j--)
			if (a[i] == '1' && a[j] == '1')
			{
				if (best == -1) best = i - j;
				if (best != i - j)
				{
					cout << "NO" << endl;
					return 0;
				}
				break;
			}
	cout << "YES" << endl;

	return 0;
}