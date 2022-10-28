#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int n, m;
char a[N][N];
int b[N][N];
int deg[N][N];
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, +1, -1};

int32_t main()
{
	IOS;
	cin >> n >> m;
	int stars = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == '*')
			{
				stars++;
				b[i][j] = 1;
			}
		}
	}
	int si = -1, sj = -1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				int ni = i + dx[k];
				int nj = j + dy[k];
				deg[i][j] += b[ni][nj];
				if(deg[i][j] == 4)
				{
					si = i;
					sj = j;
				}
			}
		}
	}
	if(si == -1)
	{
		cout << "NO";
		return 0;
	}
	if(b[si][sj] != 1)
	{
		cout << "NO";
		return 0;
	}
	stars--;
	int j = sj + 1;
	while(j <= m && b[si][j] == 1)
	{
		stars--;
		j++;
	}
	j = sj - 1;
	while(j >= 1 && b[si][j] == 1)
	{
		stars--;
		j--;
	}
	int i = si + 1;
	while(i <= n && b[i][sj] == 1)
	{
		stars--;
		i++;
	}
	i = si - 1;
	while(i >= 1 && b[i][sj] == 1)
	{
		stars--;
		i--;
	}
	if(stars == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}