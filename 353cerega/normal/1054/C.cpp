#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

using namespace std;

const int maxn = 4e4 + 5;
const long long mod = 1e9 + 7;

static long long a[maxn], b[maxn], c[maxn];
long long ans = 0;
static long long l[maxn];
static long long r[maxn];
static long long s[maxn];

void QSort(int ll, int rr)
{
	int ee = ll;
	int ff = rr;
	long long q = c[(ll + rr) / 2];
	while (ee <= ff)
	{
		while (c[ee] < q) ee++;
		while (c[ff] > q) ff--;
		if (ee <= ff)
		{
			swap(c[ee], c[ff]);
			swap(s[ee], s[ff]);
			ee++;
			ff--;
		}
	}
	if (ff > ll) QSort(ll, ff);
	if (ee < rr) QSort(ee, rr);
}

int main()
{
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> r[i];
		c[i] = l[i] + r[i];
		s[i] = i;
	}
	QSort(0, n - 1);
	a[s[n-1]] = 1;
	for (int i = n-1; i >= 1; i--)
	{
		if (c[i] == c[i - 1])
		{
			a[s[i - 1]] = a[s[i]];
		}
		else
		{
			a[s[i - 1]] = a[s[i]] + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				if (j < i)
				{
					l[i]--;
				}
				else
				{
					r[i]--;
				}
			}
		}
		if (r[i] != 0 or l[i] != 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
	
}