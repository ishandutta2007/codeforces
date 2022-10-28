#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
int a[15];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		if(x == 'L')
		{
			for(int j = 0; j <= 9; j++)
			{
				if(!a[j])
				{
					a[j] = 1;
					break;
				}
			}
		}
		else if(x == 'R')
		{
			for(int j = 9; j >= 0; j--)
			{
				if(!a[j])
				{
					a[j] = 1;
					break;
				}
			}
		}
		else
		{
			int idx = x - '0';
			a[idx] = 0;
		}
	}
	for(int i = 0; i <= 9; i++)
		cout << a[i];
	return 0;
}