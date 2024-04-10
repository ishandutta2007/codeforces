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
int a[101], n, k, sm, pat;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> sm;
		a[sm%k]++;
	}
	pat += a[0] / 2;
	for (int i = 1; i <= k/2; i++)
	{
		if (i == k - i)
			pat += a[i] / 2;
		else
			pat += min(a[i], a[k - i]);// , cout << a[i] << " " << a[k - i] << endl;
	}
	cout << pat*2;
	return 0;
}