#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;

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
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			cin >> a[i];
		}
		int cur = 0;
		for(int i = 1; i <= n; i++)
		{
			vector<pair<int, int> > v;
			for(int j = 1; j <= n; j++)
			{
				if(vis[j])
					continue;
				v.push_back({__gcd(cur, a[j]), j});
			}
			sort(v.rbegin(), v.rend());
			vis[v[0].second] = 1;
			cout << a[v[0].second] << " ";
			cur = v[0].first;
		}
		cout << endl;
	}
	return 0;
}