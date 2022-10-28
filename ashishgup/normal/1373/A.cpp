//Need to leave around 9:30

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int a, b, c;

int get(int x)
{
	int buy = x / b;
	if(x % b)
		buy++;
	return buy * c;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
		if(a < c)
			cout << 1 << " ";
		else
			cout << -1 << " ";
		if(c < a * b)
			cout << b << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}