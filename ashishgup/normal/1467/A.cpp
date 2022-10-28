//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n == 1)
			cout << 9 << endl;
		else if(n == 2)
			cout << 98 << endl;
		else
		{
			cout << 98;
			//9876....09....
			int cur = 9;
			for(int i = 0; i < n - 2; i++)
			{
				cout << cur;
				cur = (cur + 1) % 10;
			}
			cout << endl;
		}
	}
	return 0;
}