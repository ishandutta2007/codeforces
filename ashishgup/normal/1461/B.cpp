#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 505;

int n, m;
char a[N][N];
bool vis[N][N][N], cache[N][N][N];

bool check(int i, int l, int r)
{
	if(i == 0)
		return 0;
	if((r - l + 1) % 2 == 0)
		return 0;
	if(a[i][l] != '*' || a[i][r] != '*')
		return 0;
	if(l == r && a[i][r] == '*')
		return 1;
	if(vis[i][l][r])
		return cache[i][l][r];
	vis[i][l][r] = 1;
	cache[i][l][r] = check(i - 1, l + 1, r - 1) && check(i, l + 1, r - 1);
	return cache[i][l][r]; 
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int l = 1; l <= m; l++)
				for(int r = 1; r <= m; r++)
					vis[i][l][r] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				for(int l = 0; j - l >= 1 && j + l <= m; l++)
					ans += check(i, j - l, j + l);
		cout << ans << endl;
	}
	return 0;
}