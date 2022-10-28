#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], f[30];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(f, 0, sizeof(f));
		cin >> n;
		int val = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			val ^= a[i];
		}
		if(!val)
		{
			cout << "DRAW" << endl;
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 29; j >= 0; j--)
				if(a[i] >> j & 1)
					f[j]++;
		}
		int freq = 0;
		int flag = 0;
		for(int i = 29; i >= 0; i--)
		{
			if(f[i] % 2)
			{
				int have = (n - f[i]) % 2;
				f[i] %= 4;
				if(have == 1)
					flag = 1;
				else
					flag |= (f[i] == 1);
				break;
			}
		}
		if(flag)
			cout << "WIN" << endl;
		else
			cout << "LOSE" << endl;
	}
	return 0;
}