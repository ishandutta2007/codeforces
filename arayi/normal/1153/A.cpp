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
const int N = 5e4 + 30;
int n, t, pat = 2000000000, ind;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int h;
		if (t <= a)
			h = a;
		else
			h = ((t - a - 1) / b + 1) * b + a;
		if (h < pat)
		{
			ind = i + 1;
			pat = h;
		}
	}
	cout << ind;
	return 0;
}