#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

void work(int x)
{
	map<int, int> m;
	int ans = x;
	while(x > 0)
	{	
		m[x % 10]++;
		if(m[x % 10] > 1)
			return;
		x /= 10;
	}
	cout << ans;
	exit(0);
}

int32_t main()
{
	IOS;
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
		work(i);
	cout << -1;
	return 0;
}