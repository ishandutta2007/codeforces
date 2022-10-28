#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;

int32_t main()
{
	IOS;
	cin >> n >> m;
	int left = m - 1, right = (n - m);
	if(right > left)
		cout << min(n, m + 1);
	else
		cout << max(m - 1, 1LL);
	return 0;
}