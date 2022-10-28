#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 1e5 + 5;

int h, c, t;

double calc(int x)
{
	double th = x * h + x * c;
	th /= (2 * x);
	return abs(th - t);
}

int ternary_search(int lo, int hi)
{
	while(lo < hi - 2)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;
		if(calc(m1) <= calc(m2))
			hi = m2;
		else
			lo = m1;
	}
	double val = 1e9;
	int idx = lo;
	for(int i = lo; i <= hi; i++)
	{
		if(val > calc(i))
		{
			idx = i;
			val = calc(i);
		}
	}
	return idx;
}

double calc2(int x)
{
	double th = x * h + (x - 1) * c;
	th /= (2 * x - 1);
	return abs(th - t);
}

int ternary_search2(int lo, int hi)
{
	while(lo < hi - 2)
	{
		int m1 = (lo * 2 + hi) / 3;
		int m2 = (lo + hi * 2) / 3;
		if(calc2(m1) <= calc2(m2))
			hi = m2;
		else
			lo = m1;
	}
	double val = 1e9;
	int idx = lo;
	for(int i = lo; i <= hi; i++)
	{
		if(val > calc2(i))
		{
			idx = i;
			val = calc2(i);
		}
	}
	return idx;
}


int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> h >> c >> t;
		int ans = ternary_search(1, 1e12);
		int ans2 = ternary_search2(1, 1e12);
		if(calc(ans) < calc2(ans2))
			cout << ans * 2 << endl;
		else
			cout << ans2 * 2 - 1 << endl;			
	}
	return 0;
}