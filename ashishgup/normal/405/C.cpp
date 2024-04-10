#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, ans = 0;
int a[N][N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		ans ^= a[i][i];
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x <= 2)
		{
			int y;
			cin >> y;
			ans ^= 1;
		}
		else
			cout << ans;
	}
	return 0;
}