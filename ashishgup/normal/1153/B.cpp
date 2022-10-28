#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, h;
int a[N], b[N], c[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m >> h;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!c[i][j])
				cout << 0 << " ";
			else
				cout << min(b[i], a[j]) << " ";
		}
		cout << endl;
	}
	return 0;
}