#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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
#define pii pair < int, int >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 1001;
int n;
pii q[NMAX];
string ans[NMAX];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
	{
		int x;
		cin >> x;
		q[i] = mp(x, i);
	}
	sort(q, q + n);

	string now = "";
	forn(i, n)
	{
		while (q[i].fs > now.size())
			now += '0';
		ans[q[i].sc] = now;
		if (i == n - 1) break;
		
		now[now.size() - 1]++;
		int j = now.size() - 1;
		while (j > 0 && now[j] == '2')
		{
			now[j] = '0';
			now[j - 1]++;
			j--;
		}
		if (now[0] == '2')
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	forn(i, n)
		printf("%s\n", ans[i].data());

	return 0;
}