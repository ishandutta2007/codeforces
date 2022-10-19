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
int a[200];
int main()
{
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	x = a[n-1];
	for (int i = n - 1; i > 0; i--)
	{
		if (x%a[i] != 0)
		{
			cout << x << " " << a[i];
			return 0;
		}
		else if (a[i] == a[i - 1])
		{
			cout << x << " " << a[i];
			return 0;
		}
	}

	
	return 0;
}