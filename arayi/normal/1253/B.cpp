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
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 2e6 + 30;
const lli mod = 1e9 + 7;
int n, qan;
int a[N];
bool col[N], exel[N];
vector <int> pat, ex;
int main()
{
	fastio;
	pat.PB(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x < 0)
		{
			x = -x;
			if (!col[x])
			{
				cout << -1;
				return 0;
			}
			qan--;
			col[x] = false;
		}
		else
		{
			if (exel[x])
			{
				cout << -1;
				return 0;
			}
			ex.PB(x);
			exel[x] = true;
			qan++;
			col[x] = true;
		}
		if (qan == 0)
		{
			pat.PB(i + 1);
			while (!ex.empty())
			{
				exel[ex.back()] = false;
				col[ex.back()] = false;
				ex.pop_back();
			}
		}
	}
	if (qan != 0)
	{
		cout << -1;
		return 0;
	}
	cout << pat.size() - 1 << endl;
	for (int i = 0; i < pat.size() - 1; i++)
	{
		cout << pat[i + 1] - pat[i] << " ";
	}
	return 0;
}