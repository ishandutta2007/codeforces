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
const int N = 2e5 + 1;
int pat = 0, n, a[N], sm, mx;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (!a[i])
		{
			mx = max(mx, sm);
			sm = 0;
		}
		else
			sm++;
	}
	int i;
	i = 0;
	while (a[i])
	{
		i++;
		pat++;
	}
	i = n - 1;
	while (a[i])
	{
		i--;
		pat++;
	}
	cout << max(pat, mx);
	return 0;
}