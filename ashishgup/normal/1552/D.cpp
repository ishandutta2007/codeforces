#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 11;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int hasZero = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			hasZero |= (a[i] == 0);
		}
		if(hasZero)
		{
			cout << "YES" << endl;
			continue;
		}
		int flag = 0;
		for(int mask = 0; mask < (1 << n); mask++)
		{
			for(int submask = mask; submask > 0; submask = (submask - 1) & mask)
			{
				int diff = 0;
				for(int k = 0; k < n; k++)
				{
					if(submask >> k & 1)
						diff += a[k];
					if(!(mask >> k & 1))
						diff -= a[k];
				}
				if(diff == 0)
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

//b = [-9, -2, 1, 2, 3] [-9, -2, 1, 2, 3]
//a = [-7, -1, 4, 5, 10]