//Forgot to register

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int x[10], y[10];

bool isInside(double x1, double y1)
{
	if(x1 >= x[3] && x1 <= x[4] && y1 >= y[3] && y1 <= y[4])
		return 1;
	if(x1 >= x[5] && x1 <= x[6] && y1 >= y[5] && y1 <= y[6])
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	for(int i = 1; i <= 6; i++)
		cin >> x[i] >> y[i];
	for(double i = x[1]; i <= x[2]; i += 0.5)
	{
		if(!isInside(i, y[1]))
		{
			cout << "YES";
			return 0;
		}
		if(!isInside(i, y[2]))
		{
			cout << "YES";
			return 0;
		}
	}
	for(double i = y[1]; i <= y[2]; i += 0.5)
	{
		if(!isInside(x[1], i))
		{
			cout << "YES";
			return 0;
		}
		if(!isInside(x[2], i))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}