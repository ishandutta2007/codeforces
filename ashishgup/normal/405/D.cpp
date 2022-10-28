#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;

int n, s = 1e6, cur = 1;
int a[N];
bool have[N], vis[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		have[a[i]] = 1;
	}	
	cout << n << endl;
	for(int i = 1; i <= n; i++)
	{
		if(!have[s - a[i] + 1])
			cout << s - a[i] + 1 << " ";
		else
		{	
			if(vis[a[i]])
				continue;
			while(have[cur] || have[s - cur + 1])
				cur++;
			cout << cur << " " << s - cur + 1 << " ";
			vis[a[i]] = 1;
			vis[s - a[i] + 1] = 1;
			have[cur] = 1;
			have[s - cur + 1] = 1;
		}
	}
	return 0;
}