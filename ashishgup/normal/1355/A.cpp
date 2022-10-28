#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

pair<int, int> get(int x)
{
	int mn = 9, mx = 0;
	while(x > 0)
	{
		int cur = x % 10;
		mn = min(mn, cur);
		mx = max(mx, cur);
		x /= 10;
	}
	return {mn, mx};
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a1, k;
		cin >> a1 >> k;
		int prv = a1;
		for(int i = 2; i <= k; i++)
		{
			pair<int, int> p = get(prv);
			int nxt = prv + p.first * p.second;
			if(nxt == prv)
				break;
			prv = nxt;
		}
		cout << prv << endl;
	}
	return 0;
}