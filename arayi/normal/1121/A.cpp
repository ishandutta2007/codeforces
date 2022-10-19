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
const int N = 1e5 + 1;
int n, k, m, pat;
int mx[101], b[101], c[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		mx[c[i]] = max(mx[c[i]], b[i]);
	}
	for (int i = 0; i < k; i++)
	{
		int sm;
		cin >> sm;
		if (mx[c[sm]] != b[sm])
			pat++;
	}
	cout << pat;
	return 0;
}