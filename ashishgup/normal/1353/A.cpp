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
		int n, m;
		cin >> n >> m;
		if(n == 1)
			cout << 0 << endl;
		else if(n == 2)
			cout << m << endl;
		else
			cout << 2 * m << endl;
	}
	return 0;
}