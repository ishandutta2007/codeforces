#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;

int n;
char a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		int ans = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] == '1')
				{
					int cur = 0;
					if(i == n)
						cur = 1;
					if(j == n)
						cur = 1;
					if(i + 1 <= n)
						if(a[i + 1][j] == '1')
							cur = 1;
					if(j + 1 <= n)
						if(a[i][j + 1] == '1')
							cur = 1;
					ans &= cur;
				}
			}
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}