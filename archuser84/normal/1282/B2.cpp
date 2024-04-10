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
		int a[300000];
		int sum[300000] = { 0 };
		int maax[300000] = { 0 };
		for (LoopN)
			cin >> a[i];
		sort(a, a + n);
		/*int Ks[300000] = { 0 };
		for (int i = k - 1; i < n; i += k)
		{
			if (p >= a[i])
			{
				p -= a[i];
				for (int j = 0; j < k; ++j)
					Ks[j] += a[i + j];
			}
		}*/
		for (int i = 1; i < k; ++i)
		{
			if (sum[i - 1] + a[i-1] <= p)
			{
				sum[i] = sum[i - 1] + a[i-1];
				maax[i] = maax[i - 1] + 1;
			}
		}
		int L = k;
		for (int i = k - 1; i < n; i += k)
		{
			int l = k;
			int h = L;
			for (int j = 0; j < h; ++j)
			{
				if (i + j < n && sum[j] + a[i + j] <= p)
				{
					maax[j] += k;
					sum[j] += a[i + j];
					L = j + 1;
				}
				else
				{
					if (l == k)
						l = j;
				}
			}
			if (l == 0)
			{
				break;
			}
		}
		int ans = 0;
		for (int i = 1; i < k; ++i)
			if (maax[i] > maax[ans])
				ans = i;
		cout << maax[ans] << '\n';
	}
}