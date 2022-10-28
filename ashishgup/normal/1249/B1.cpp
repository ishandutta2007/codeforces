#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], ans[N];
bool vis[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			vis[i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			if(vis[i])
				continue;
			int cur = a[i];
			int len = 0;
			vector<int> v;
			while(!vis[cur])
			{
				v.push_back(cur);
				len++;
				vis[cur] = 1;
				cur = a[cur];
			}
			for(auto &it:v)
				ans[it] = len;
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}