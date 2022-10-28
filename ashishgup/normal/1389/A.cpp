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
		int l, r;
		cin >> l >> r;
		if(l * 2 <= r)
			cout << l << " " << l * 2 << endl;
		else
			cout << -1 << " " << -1 << endl;
	}
	return 0;
}