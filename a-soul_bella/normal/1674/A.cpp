#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		if(b%a==0)
		{
			cout << 1 << " " << b/a << "\n";
		}
		else cout << "0 0\n";
	}
	return 0;
}