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

int const P = 32768;
int ans, n, f[40000], num, p, l;
string s[100], S;

int exp();

int mn()
{
	if (S[l] == 'n')
	{
		l++;
		return n;
	}
	if (S[l] == 'f')
	{
		l += 2;
		int res = f[exp()];
		l++;
		return res;
	}
	int res = 0;
	while (S[l] >= '0' && S[l] <= '9')
		res = res * 10 + S[l++] - '0';
	return res;
}

int sl()
{
	int res = mn();
	while (S[l] == '*' || S[l] == '/')
	{
		char zn = S[l++];
		int tmp = mn();
		if (zn == '*') res = (int) (((long long) res * tmp) % P);
		else res = (res / tmp) % P;
	}
	return res;
}

int exp()
{
	int res = sl();
	while (S[l] == '+' || S[l] == '-')
	{
		char zn = S[l++];
		int tmp = sl();
		if (zn == '+') res = (res + tmp) % P;
		else res = (P + res - tmp) % P;
	}
	return res;
}

bool lexp()
{
	int p1, p2, tp;
	p1 = exp();
	if (S[l] == '=') tp = 0, l += 2;
	else if (S[l] == '<') tp = -1, l++;
	else tp = 1, l++;
	p2 = exp();
	if (tp == 0 && p1 == p2) return true;
	if (tp == -1 && p1 < p2) return true;
	if (tp == 1 && p1 > p2) return true;
	return false;
}

int solve()
{
	forn(i, num)
	{
		S = s[i];
		if (S[0] == 'i')
		{
			l = 3;
			if (lexp())
			{
				l += 7;
				return exp();
			}
		}
		else
		{
			l = 6;
			return exp();
		}
	}
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	char ch;
	cin >> ans;
	cin >> ch;
	while (ch != '{')
		cin >> ch;

	num = 0;
	while (true)
	{
		cin >> ch;
		if (ch == '}') break;
		if (ch == ';')
		{
			num++;
			continue;
		}
		if (ch > ' ') s[num] += ch;
	}

	int answer = -1;
	forn(i, P)
	{
		n = i;
		f[n] = solve();
		if (f[n] == ans) answer = n;
	}
	cout << answer << endl;

	return 0;
}