//Started 40 mins late :(

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, k;
int ans[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int mx = (n - 1) / 2;
		if(k > mx)
			cout << -1 << endl;
		else
		{
			int val = 1;
			int left = mx - k;
			for(int i = 1; i <= n; i++)
				ans[i] = i;
			for(int i = 3; i <= n && k--; i += 2)
				swap(ans[i], ans[i - 1]);
			for(int i = 1; i <= n; i++)
				cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}