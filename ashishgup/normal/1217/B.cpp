#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, x;
int d[N], h[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x;
		int mx = 0, redMax = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> d[i] >> h[i];
			mx = max(mx, d[i]);
			redMax = max(redMax, d[i] - h[i]);
		}
		if(redMax <= 0 && mx < x)
			cout << -1 << endl;
		else if(mx >= x)
			cout << 1 << endl;
		else
		{
			int diff = x - mx;
			int ans = 1 + ((diff + redMax - 1)/ redMax);
			cout << ans << endl;
		}

	}
	return 0;
}