#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int __int128
 
const int N = 2e5 + 5;

int k, l, r, t, x, y;

int32_t main()
{
	IOS;
	int64_t kk, ll, rr, tt, xx, yy;
	cin >> kk >> ll >> rr >> tt >> xx >> yy;
	k = kk, l = ll, r = rr, t = tt, x = xx, y = yy;
	if(k + y <= r)
		k += y;
	if(y <= x)
	{
		int diff = x - y;
		int secondlast = k -  (t - 1) * diff;
		secondlast -= x;
		if(secondlast <= l - 1)
			cout << "No";
		else
			cout << "Yes";
		return 0;
	}
	//REPLACE 64_t with 128_t
	int days = 0;
	int inc = (y - x);
	int lim = max((int)0, (r - y + inc));
	days += (max((int)0, lim - k)) / inc;
	k += days * inc;
	if(days >= t)
	{
		cout << "Yes";
		return 0;
	}
	map<int, int> vis;
	int curVal = k;
	while(!vis.count(curVal))
	{
		vis[curVal] = 1;
		int lo = 0, hi = 1e18;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			int val = curVal - mid * x;
			if(val + y <= r)
				hi = mid;
			else
				lo = mid + 1;
		}
		int val = curVal - lo * x;
		if(val < l)
		{
			int haveDays = (curVal - l) / x;
			days += haveDays;
			if(days >= t)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			return 0;
		}
		days += lo;
		curVal = val;
		if(curVal + y <= r)
			curVal += y;
	}
	cout << "Yes";
	return 0;
}