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
int a[N], n, m, k, pat[N], t, ii, i1;
lli sum;
pair <int, int> b[N];
lli msum()
{
	lli sum2 = 0;
	for (int i = n - 1; i >= n - k * m; i--)
	{
		sum2 += b[i].fr;
	}
	return sum2;
}
priority_queue <int> fsum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	int k1 = k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i].fr = a[i];
		b[i].sc = i;
	}
	sort(b, b + n);
	cout << msum() << endl;
	ii = n - k * m;
	int ii1 = ii - 1;
	while (ii1 >= 0 && b[ii1].fr == b[ii].fr)
	{
		a[b[ii1].sc]--;
		ii1--;
	}
	for (int i = 0; i < n;)
	{
		t = 0;
		while ((t < m || k == 1) && i < n)
		{
			if (a[i] >= b[ii].fr)
				t++;
			i++;
		}
		k--;
		i1++;
		pat[i1] = i;
	}
	
	for (int i = 1; i < k1; i++)
	{
		cout << pat[i] << " ";
	}
	return 0;
}