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
int n;
int a[N];
lli sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n/2; i++)
	{
		sum += (a[i] + a[n - i - 1])*(a[i] + a[n - i - 1]);
	}
	cout << sum;
	return 0;
}