#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int x, s;
	cin >> x >> s;
	if(x == s)
	{
		if(x == 0)
			cout << 0;
		else
		{
			cout << 1 << endl;
			cout << x;
		}
		return 0;
	}
	if(x > s)
	{
		cout << -1;
		return 0;
	}
	if((s - x) % 2)
	{
		cout << -1;
		return 0;
	}
	bool flag = 1;
	int andVal = s - x;
	andVal >>= 1;
	int val1 = 0, val2 = 0;
	for(int i = 60; i >= 0; i--)
	{
		int b1 = (x >> i) & 1;
		int b2 = (andVal >> i) & 1;
		if(b1 && b2)
		{
			flag = 0;
			break;
		}
		else if(b1)
			val1 |= (1LL << i);
		else if(b2)
			val1 |= (1LL << i), val2 |= (1LL << i);
	}
	if(flag && (val1 ^ val2) == x && (val1 + val2) == s)
	{
		cout << 2 << endl;
		cout << val1 << " " << val2;
		return 0;
	}
	if((s - x) % 2 == 0)
	{
		cout << 3 << endl;
		cout << x << " " << (s - x) / 2 << " " << (s - x) / 2;
		return 0;
	}
	cout << -1;
	return 0;
}