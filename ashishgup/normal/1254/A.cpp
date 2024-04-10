#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, k, tot = 0;
char a[N][N];
int ans[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		tot = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == 'R')
					tot++;
			}
		}
		int reqd = tot / k;
		int extra = tot % k;
		int cur = 0;
		int keep = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i % 2 == 0)
			{	
				int j = 1;	
				while(j <= m)
				{
					cur += (a[i][j] == 'R');
					ans[i][j] = keep;
					if(cur == reqd + (extra > 0))
					{
						keep++;
						extra--;
						cur = 0;
						keep = min(keep, k - 1);
					}
					j++;
				}
			}
			else
			{
				int j = m;
				while(j >= 1)
				{
					cur += (a[i][j] == 'R');
					ans[i][j] = keep;
					if(cur == reqd + (extra > 0))
					{
						keep++;
						extra--;
						cur = 0;
						keep = min(keep, k - 1);
					}
					j--;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(ans[i][j] <= 25)
					cout << (char)('a' + ans[i][j]);
				else if(ans[i][j] <= 51)
					cout << (char)('A' + ans[i][j] - 26);
				else
					cout << (char)('0' + ans[i][j] - 52);
			}
			cout << endl;
		}
	}
	return 0;
}