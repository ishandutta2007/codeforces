#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m;
int a[N], p[N], mark[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(mark, 0, sizeof(mark));
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= m; i++)
		{
			cin >> p[i];
			mark[p[i]] = 1;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j + 1 <= n; j++)
			{
				if(mark[j] && a[j] > a[j + 1])
					swap(a[j], a[j + 1]);
			}
		}
		int sorted = 1;
		for(int i = 1; i + 1 <= n; i++)
			sorted &= (a[i] <= a[i + 1]);
		if(!sorted)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}