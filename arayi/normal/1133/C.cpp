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
const int N = 3e5 + 1;
int a[N], n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0, r = 0, mx = 0;
	while (r < n)
	{
		while (r < n && a[r] - a[l] <= 5)
		{
			r++;
		}
		mx = max(mx, r - l);
		while (a[r] - a[l] > 5)
		{
			l++;
		}
	}
	cout << mx;
	return 0;
}