#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i += 2)
	{
		int bal = a[i], mn = a[i];
		for(int j = i + 1; j <= n; j++)
		{
			if(i % 2 != j % 2)
			{
				if(a[j] + mn >= bal)
				{
					if(j == i + 1)
						ans--; //Remove empty subseq
					int val1 = mn + 1; //x + y == cur, x is [0...mn]
					int val2 = a[j] + 1 - bal + mn; //y >= cur - mn
					ans += min(val1, val2);

				}
				bal -= a[j];
				mn = min(mn, bal);
			}
			else
				bal += a[j];
			if(bal < 0)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}