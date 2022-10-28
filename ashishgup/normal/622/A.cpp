#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	int lo = 0, hi = 1e9;
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(mid * (mid + 1) / 2 < n)
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << n - lo * (lo + 1) / 2;
	return 0;
}