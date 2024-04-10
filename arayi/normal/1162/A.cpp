#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 100030;
int a[60], n, h, l, r, x, pat;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> h >> x;
	for (int i = 0; i <= n; i++)
	{
		a[i] = h;
	}
	for (int i = 0; i < x; i++)
	{
		cin >> l >> r >> h;
		for (int j = l; j <= r; j++)
		{
			a[j] = min(a[j], h);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		pat += a[i] * a[i];
	}
	cout << pat;
	return 0;
}