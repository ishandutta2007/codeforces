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
lli n, a[N];
lli H, pat, mx, sum, sm;
int main() {

	cin >> H >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		mx = min(mx, sum);
	}
	if (H + mx > 0 && sum >= 0)
	{
		cout << -1;
		return 0;
	}
	if (H + mx <= 0)
	{
		sm = 0;
	}
	else
		sm = (H + mx - 1) / (-sum) + 1;
	pat = sm * n;
	H += sm * sum;
	//cout << H << " " << pat;
	int i = 0;
	while (H > 0)
	{
		pat++;
		H += a[i];
		i++;
	}
	cout << pat;
	return 0;
}