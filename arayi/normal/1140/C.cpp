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
const int N = 3e5 + 2;
lli n, k, suf[N], sum, pat, mx;
multiset <lli> sm;
multiset <lli>::iterator it;
struct el
{
	int a, b;
};
bool operator<(const el &x, const el &y)
{
	return x.b < y.b;
}
el a[N];
int main() 
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].a >> a[i].b;
	}
	sort(a, a + n);
	if (k > 1)
	{
		for (int i = n - 1; i >= (n - k + 1); i--)
		{
			suf[i] = suf[i + 1] + a[i].a;
			sm.insert(a[i].a);
		}
		sum = suf[n - k + 1];
		for (int i = n - k; i >= 0; i--)
		{
			it = sm.begin();
			if (a[i].a > *it)
			{
				sum += a[i].a - *it;
				sm.insert(a[i].a);
				sm.erase(it);
			}
			suf[i] = sum;
		}
	}
	for (int i = 0; i < n; i++)
	{
		mx = a[i].b*(a[i].a + suf[i + 1]);
		//cout << mx << endl;
		pat = max(mx, pat);
	}
	cout << pat;
	return 0;
}