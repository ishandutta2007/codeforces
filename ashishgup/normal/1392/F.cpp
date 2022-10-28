#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 1e6 + 5;

int n, sum = 0;
int a[N];

int get(int l, int n)
{
	return n * (n + 1) / 2 + (l - 1) * n;
}

double getd(double l, double n)
{
	return n * (n + 1) / 2 + (l - 1) * n;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int lo = a[1], hi = a[n];
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		double val = getd(mid, n);
		if(val > sum + 1e18)
			hi = mid - 1;
		else
		{
			int value = get(mid, n);
			if(value > sum)
				hi = mid - 1;
			else
				lo = mid;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = lo + i - 1;
		sum -= a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(sum > 0)
		{
			sum--;
			a[i]++;
		}
		cout << a[i] << " ";
	}
	return 0;
}