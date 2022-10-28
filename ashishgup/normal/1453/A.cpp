#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n, m;
int a[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		map<int, int> freq;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}
		int ans = 0;
		for(int i = 1; i <= m; i++)
		{
			cin >> b[i];
			ans += freq[b[i]];
		}
		cout << ans << endl;
	}
	return 0;
}