#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int n, p, k;
		cin >> n >> p >> k;
		int P = p;
		int a[300000];
		int sum=0;
		for (LoopN)
			cin >> a[i];
		sort(a, a + n);
		/*int x = (n / k) * k;
		for (int i = k-1; i < n; i+=k)
		{
			if (p >= a[i])
			{
				sum += k;
				p -= a[i];
			}
			else
			{
				x = i - (k - 1);
				break;
			}
		}
		for (int i = x; i < n; ++i)
		{
			if (p >= a[i])
			{
				sum += 1;
				p -= a[i];
			}
			else
			{
				break;
			}
		}*/
		if (p >= a[0])
		{
			++sum;
			p -= a[0];
		}
		for (int i = k; i < n; i += k)
		{
			if (p >= a[i])
			{
				sum += k;
				p -= a[i];
			}
			else
				break;
		}
		int sum2 = 0;
		p = P;
		for (int i = k-1; i < n; i += k)
		{
			if (p >= a[i])
			{
				sum2 += k;
				p -= a[i];
			}
			else
				break;
		}
		cout << max(sum,sum2) << '\n';
	}
}