#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 20;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int len = n; len >= 1; len /= 2)
	{
		for(int start = 1; start + len - 1 <= n; start += len)
		{
			bool check = 1;
			int prev = 0;
			for(int i = start; i <= start + len - 1; i++)
			{
				check &= (a[i] >= prev);
				prev = a[i];
			}
			if(check)
			{
				cout << len;
				exit(0);
			}
		}
	}
	return 0;
}