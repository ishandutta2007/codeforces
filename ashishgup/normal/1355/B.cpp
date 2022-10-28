#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		map<int, int> m;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		int ans = 0;
		int have = 0;
		for(auto &it:m)
		{
			int canTake = (it.second + have) / it.first;
			have = (it.second + have) % it.first;
			ans += canTake;
		}
		cout << ans << endl;
	}
	return 0;
}