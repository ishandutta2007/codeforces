#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli cg(lli n) {
	return n ^ (n >> 1);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m, int a)
{
	if (x >= a && y >= a && x < n && y < m)
	{
		return true;
	}
	return false;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
using namespace std;
const int N = 1e6 + 30;
const lli mod = 1e9 + 7;
int h, w;
char b[510][510];
int a[510][510];
void stg(int i, int j)
{
	int i1 = i + 1, j1 = j;
	for (; i1 < h; i1++)
	{
		if (!a[i1][j1]) break;
		a[i1][j1] = 0;
	}
	i1 = i - 1, j1 = j;
	for (; i1 >= 0; i1--)
	{
		if (!a[i1][j1]) break;
		a[i1][j1] = 0;
	}
	i1 = i, j1 = j - 1;
	for (; j1 >= 0; j1--)
	{
		if (!a[i1][j1]) break;
		a[i1][j1] = 0;
	}
	i1 = i, j1 = j + 1;
	for (; j1 < w; j1++)
	{
		if (!a[i1][j1]) break;
		a[i1][j1] = 0;
	}
}
bool st()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j])
				return false;
		}
	}
	return true;
}
void tp()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	fastio;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '*')
				a[i][j] = 1;
		}
	}
	for (int i = 1; i < h - 1; i++)
	{
		for (int j = 1; j < w - 1; j++)
		{
			if (a[i][j] + a[i + 1][j] + a[i - 1][j] + a[i][j + 1] + a[i][j - 1] == 5)
			{
				stg(i, j);
				a[i][j] = 0;
				//tp();
				if (st()) cout << "YES";
				else cout << "NO";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}