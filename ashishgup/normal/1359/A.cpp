#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int win = min(m, n / k);
		int rem = m - win;
		int remMax = (rem + k - 2) / (k - 1);
		cout << (win - remMax) << endl;
	}
	return 0;
}