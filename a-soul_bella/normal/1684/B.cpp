#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e8;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int x=a,y=b,z;
		x+=inf*b;
		z=c+x;
		cout << x << " " << y << " " << z << "\n";
//		cout << x%y << " " << y%z << " " << z%x << "\n";
	}
	return 0;
}