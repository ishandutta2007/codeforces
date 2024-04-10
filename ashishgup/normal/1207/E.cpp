#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	cout << "? ";
	for(int i = 0; i <= 99; i++)
	{
		cout << i;
		if(i != 99)
			cout << " ";
	}
	cout << endl;
	int x;
	cin >> x;
	cout << "? ";
	for(int i = 1; i <= 100; i++)
	{
		int cur = i << 7;
		cout << cur;
		if(i != 100)
			cout << " ";
	}
	cout << endl;
	int y;
	cin >> y;
	int ans = 0;
	for(int b = 0; b <= 6; b++)
	{
		if(y >> b & 1)
			ans += (1 << b);
	}
	for(int b = 7; b <= 13; b++)
	{
		if(x >> b & 1)
			ans += (1 << b);
	}
	cout << "! ";
	cout << ans;
	return 0;
}