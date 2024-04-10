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
int rk[N], a[1001], n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			rk[a[i] + a[j]]++;
		}
	}
	int mx = 0;
	for (int i = 0; i < N; i++)
	{
		mx = max(mx, rk[i]);
	}
	cout << mx;
	return 0;
}