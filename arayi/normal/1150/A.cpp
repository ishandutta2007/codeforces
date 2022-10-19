#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 50030;
int n, m, r, qan;
int mn = 1010, mx = 0;
int main()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		mn = min(mn, a);
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		mx = max(mx, a);
	}
	if (mx <= mn)
	{
		cout << r;
		return 0;
	}
	qan = r / mn;
	r -= qan * mn;
	r += qan * mx;
	cout << r;
	return 0;
}