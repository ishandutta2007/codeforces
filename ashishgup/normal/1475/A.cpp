//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		while(n % 2 == 0)
			n /= 2;
		if(n > 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}