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
const int N = 1e5 + 30;
int n, m, x, a[N], sm, b[N], X[N];
lli pat;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		b[i] = 10;
	}
	for (int i = 0; i < m; i++)
	{	
		cin >> X[i];
	}
	for (int i = m - 1; i >= 0; i--)
	{
		sm = 0;
		x = X[i];
		a[x] = 1;
		if (x > 1 && !a[x - 1]) sm++;
		if (x < n && !a[x + 1]) sm++;
		b[x] = min(b[x], sm);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!a[i])
		{
			pat++;
			if (i > 1)
				pat++;
			if (i < n)
				pat++;
		}
		else
			pat += b[i];
	}
	cout << pat;
	return 0;
}