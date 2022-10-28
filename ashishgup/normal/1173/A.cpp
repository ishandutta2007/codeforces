#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	int x, y, z;
	cin >> x >> y >> z;
	int diff = abs(x - y);
	if(z > 0 && z >= diff)
		cout << "?";
	else
	{
		if(x > y)
			cout << "+";
		else if(x == y)
			cout << "0";
		else
			cout << "-";
	}
	return 0;
}