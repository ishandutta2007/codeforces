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
int n, a[N], m, sm;
lli sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> sm;
		cout << sum - a[n - sm] << endl;
	}
	return 0;
}