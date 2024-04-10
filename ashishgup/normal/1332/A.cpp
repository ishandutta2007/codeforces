#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int a, b, c, d;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int fx = x + (b - a);
		int flag = 1;
		if(fx < x1 || fx > x2)
			flag = 0;
		if(x1 == x2 && (a > 0 || b > 0))
			flag = 0;
		int fy = y + (d - c);
		if(fy < y1 || fy > y2)
			flag = 0;
		if(y1 == y2 && (c > 0 || d > 0))
			flag = 0;
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}