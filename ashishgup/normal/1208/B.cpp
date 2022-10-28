#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2005;

int n;
int a[N];
map<int, int> f;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	int exceed = 0;
	for(auto &it:f)
		exceed += (it.second > 1);
	int ans = n;
	if(exceed == 0)
		ans = 0;
	for(int i = 1; i <= n; i++)
	{
		bool check = 0;
		for(int j = i; j <= n; j++)
		{
			f[a[j]]--;
			if(f[a[j]] == 1)
				exceed--;
			if(exceed == 0)
			{
				check = 1;
				for(int k = i; k <= j; k++)
				{
					f[a[k]]++;
					if(f[a[k]] == 2)
						exceed++;
				}
				ans = min(ans, j - i + 1);
				break;
			}
		}
		if(!check)
		{
			for(int j = i; j <= n; j++)
			{
				f[a[j]]++;
				if(f[a[j]] == 2)
					exceed++;
			}
		}
	}
	cout << ans;
	return 0;
}