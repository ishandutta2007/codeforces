#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int store[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	for(int i = 2; i <= 5e4; i++)
		store[i] = i * (i - 1) / 2;
	while(t--)
	{
		int n;
		cin >> n;
		int rem = n;
		for(int i = 5e4; i >= 2; i--)
		{
			int take = rem / store[i];
			for(int j = 1; j <= take; j++)
				cout << 1;
			rem %= store[i];
			if(i != 2)
				cout << 3;
		}
		cout << 337 << endl;
	}
	return 0;
}