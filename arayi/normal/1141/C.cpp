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
int q[N], a[N], n, ind, mx, sum;
void tp()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i + 1] << " ";
	}
}
int main() {

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> q[i];
		sum += q[i];
		if (sum > mx)
		{
			mx = sum;
			ind = i;
		}
	}
	ind++;
	a[ind] = n;
	for (int i = ind - 1; i >= 0; i--)
	{
		a[i] = a[i + 1] - q[i];
	}
	for (int i = ind; i < n; i++)
	{
		a[i + 1] = a[i] + q[i];
	}
	set <int> st;
	for (int i = 0; i < n; i++)
	{
		st.insert(a[i + 1]);
		if (a[i + 1] < 1 || a[i + 1] > n)
		{
			cout << -1;
			return 0;
		}
	}
	if (st.size() < n)
	{
		cout << -1;
		return 0;
	}
	tp();
	return 0;
}