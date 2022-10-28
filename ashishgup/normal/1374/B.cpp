#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int get(int &x, int y)
{
	int ans = 0;
	while(x % y == 0)
	{
		ans++;
		x /= y;
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ct2 = get(n, 2);
		int ct3 = get(n, 3);
		if(n > 1 || ct3 < ct2)
			cout << -1 << endl;
		else
			cout << ct3 + ct3 - ct2 << endl;
	}
	return 0;
}