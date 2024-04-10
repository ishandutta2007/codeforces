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
using lli = long long int;
using namespace std;
const int N = 100010;
const int mod = 1000000;
int za, ka, zb, kb;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a % 2 == 0)
			za++;
		else
			ka++;
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a % 2 == 0)
			zb++;
		else
			kb++;
	}
	cout << min(za, kb) + min(zb, ka);
	return 0;
}