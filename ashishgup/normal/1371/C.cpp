#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int a, b, n, m;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> n >> m;
		if(min(a, b) >= m && a + b >= n + m)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}