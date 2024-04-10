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
		int n, k1 , k2;
		cin >> n >> k1 >> k2;
		int ans = 0;
		for(int i = 1; i <= k1; i++)
		{
			int x;
			cin >> x;
			ans |= (x == n);
		}
		for(int i = 1; i <= k2; i++)
		{
			int x;
			cin >> x;
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}