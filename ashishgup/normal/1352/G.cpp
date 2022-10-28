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
		int n;
		cin >> n;
		if(n <= 3)
			cout << "-1" << endl;
		else
		{
			vector<int> fix = {2, 4, 1, 3};
			vector<int> c6 = {1, 4, 2, 6, 3, 5};
			vector<int> c7 = {1, 4, 2, 6, 3, 5, 7};
			if(n % 4 == 0)
			{
				int inc = 0;
				for(int i = 1; i <= n / 4; i++)
				{
					for(auto &it:fix)
						cout << it + inc << " ";
					inc += 4;
				}
				cout << endl;
			}
			else if(n % 4 == 1)
			{
				int inc = 0;
				for(int i = 1; i <= n / 4; i++)
				{
					for(auto &it:fix)
						cout << it + inc << " ";
					inc += 4;
				}
				cout << n << endl;
			}
			else if(n % 4 == 2)
			{
				int inc = 0;
				for(int i = 1; i <= n / 4 - 1; i++)
				{
					for(auto &it:fix)
						cout << it + inc << " ";
					inc += 4;
				}
				for(auto &it:c6)
					cout << it + inc << " ";
				cout << endl;
			}
			else if(n % 4 == 3)
			{
				int inc = 0;
				for(int i = 1; i <= n / 4 - 1; i++)
				{
					for(auto &it:fix)
						cout << it + inc << " ";
					inc += 4;
				}
				for(auto &it:c7)
					cout << it + inc << " ";
				cout << endl;
			}
		}
	}
	return 0;
}