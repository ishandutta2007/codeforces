#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	if(k == 1)
		cout << n;
	else
	{
		for(int b = 60; b >= 0; b--)
		{
			if(n >> b & 1)
			{
				cout << (1LL << (b + 1)) - 1;
				return 0;
			}
		}
	}
	return 0;
}