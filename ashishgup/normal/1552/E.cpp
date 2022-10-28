#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e4 + 5;

int n, k;
int a[N], prv[N];
int ans1[N], ans2[N];
bool vis[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int cnt = 1; cnt <= n; cnt++)
	{
		int flag = 0;
		memset(prv, 0, sizeof(prv));
		for(int i = 1; i <= n * k; i++)
		{
			cin >> a[i];
			if(vis[a[i]])
				continue;
			if(prv[a[i]])
			{
				vis[a[i]] = 1;
				ans1[a[i]] = prv[a[i]], ans2[a[i]] = i;
				memset(prv, 0, sizeof(prv));
				flag = 1;
			}
			prv[a[i]] = i;
		}
		if(!flag)
			break;
	}
	for(int i = 1; i <= n; i++)
	{
		assert(ans1[i] > 0);
		cout << ans1[i] << " " << ans2[i] << endl;
	}
	return 0;
}