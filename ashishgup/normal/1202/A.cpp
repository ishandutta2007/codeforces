#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string x, y;
		cin >> x >> y;
		int skip = 0;
		for(int i = y.size() -  1; i >= 0; i--)
		{
			if(y[i] == '1')
				break;
			skip++;
		}
		int ans = 0;
		for(int i = x.size() - 1 - skip; i >= 0; i--)
		{
			if(x[i] == '1')
				break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}