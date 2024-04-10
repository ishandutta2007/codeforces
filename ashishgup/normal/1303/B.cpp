#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
	
int n, g, b;

int calc(int x)
{
	int tot = x / (g + b);
	x %= (g + b);
	int totG = tot * g;
	int totB = tot * b;
	totG += min(g, x);
	totB += max(0LL, x - g);
	int have = totG + min(totB, totG);
	return have;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> g >> b;
		int lo = 1, hi = 1e18;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			if(calc(mid) >= n)
				hi = mid;
			else
				lo = mid + 1;
		}
		cout << lo << endl;
	}
	return 0;
}