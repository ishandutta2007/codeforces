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
const int N = 5e5 + 1;
int a[101][2], n, k;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		if (k >= a[i][0] && a[i][1] >= k)
		{
			cout << n - i;
			return 0;
		}
	}
	return 0;
}