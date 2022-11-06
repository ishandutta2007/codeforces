#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int n, a[1000];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		cin >> a[i];

	forn(i, n)
		forn(j, n)
			forn(f, n)
				if (i != j && i != f && f != j && a[i] == a[j] + a[f])
				{
					cout << i + 1 << " " << j + 1 << " " << f + 1 << endl;
					return 0;
				}
	cout << -1 << endl;

	return 0;
}