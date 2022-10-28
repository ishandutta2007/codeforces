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
		int x;
		cin >> x;
		if(x >= 15 && (x % 14) <= 6 && (x % 14) >= 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}