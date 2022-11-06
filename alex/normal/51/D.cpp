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
#define pii pair < long long, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int n, a[200001], p[200001];
vector <double> b;

bool eq(double x, double y)
{
	if (fabs(x - y) > 1e-8) return false;
	else return true;
}

bool check(int n)
{
	if (n <= 2)
	{
		if (n ==2 && p[0] == 0 && p[1] == 0 || n == 1 || p[0] != 0) 
			return true;
		else 
			return false;
	}
	double B;
	if (p[0] == 0) B = 0;
	else B = (double) p[1] / p[0];
	for (int i = 1; i < n; i++)
		if (!eq(p[i], p[i - 1] * B)) return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);

	//all
	forn(i, n)
		p[i] = a[i];
	if (check(n))
	{
		cout << 0 << endl;
		return 0;
	}

	if (n < 100)
	{
		forn(i, n)
		{
			int now = 0;
			forn(j, n)
				if (j != i) p[now++] = a[j];
			if (check(n - 1))
			{
				cout << 1 << endl;
				return 0;
			}
		}
		cout << 2 << endl;
		return 0;
	}
	
	//first
	forn(i, n - 1)
		p[i] = a[i + 1];
	if (check(n - 1))
	{
		cout << 1 << endl;
		return 0;
	}

	//try 0 in the end
	{
	int cnt = 0;
	forn(i, n)
		if (i && a[i] == 0) cnt++;
	if (cnt > 1 && cnt < n - 2)
	{
		cout << 2 << endl;
		return 0;
	}
	if (cnt == n - 2)
	{
		cout << 1 << endl;
		return 0;
	}
	}
	
	// remove 0
	forn(i, n)
		if (a[i] == 0)
		{
			int now = 0;
			forn(j, n)
				if (j != i) p[now++] = a[j];
			if (check(n  -1))
				cout << 1 << endl;
			else
				cout << 2 << endl;
			return 0;
		}

	//first
	forn(i, n - 1)
		p[i] = a[i];
	if (check(n - 1))
	{
		cout << 1 << endl;
		return 0;
	}

	// main
	forn(i, n - 1)
		b.pb((double) a[i] / a[i + 1]);
	sort(all(b));
	int cnt = 0, best = 0;
	double B = 0;
	sort(all(b));
	b.pb(b[0] - 1);
	forn(i, b.size())
		if (!i || !eq(b[i], b[i - 1]))
		{
			if (i && best < cnt)
			{
				best = cnt;
				B = b[i - 1];
			}
				cnt = 1;
		}
		else cnt++;

	for (int i = 1; i < n - 1; i++)
	{
		int now = best;
		if (eq((double) a[i] / a[i + 1], B)) now--;
		if (eq((double) a[i - 1] / a[i], B)) now--;
		if (eq((double) a[i - 1] / a[i + 1], B)) now++;
		if (now == n - 2)
		{
			cout << 1 << endl;
			return 0;
		}
	}

	cout << 2 << endl;

	return 0;
}