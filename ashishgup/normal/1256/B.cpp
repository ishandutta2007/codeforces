#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
int a[N];
bool vis[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n - 1; i++)
		{
			int mn = n + 1;
			int idx = 1;
			for(int j = 1; j + 1 <= n; j++)
			{
				if(a[j + 1] < mn && !vis[j])
				{
					mn = a[j + 1];
					idx = j;
				}
			}
			if(a[idx + 1] < a[idx])
				swap(a[idx], a[idx + 1]);
			vis[idx] = 1;
		}
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}