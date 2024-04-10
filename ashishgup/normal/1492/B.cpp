//Started 2 mins late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

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
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		map<int, int> vis;
		int cur = n, idx = n;
		for(int i = n; i >= 1; i--)
		{
			while(vis[cur])
				cur--;
			if(cur == a[i])
			{
				for(int j = i; j <= idx; j++)
					cout << a[j] << " ";
				idx = i - 1;
			}
			vis[a[i]] = 1;
		}
		cout << endl;
	}
	return 0;
}