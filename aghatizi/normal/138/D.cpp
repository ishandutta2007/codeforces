#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 22;
const int maxm = maxn * 2;

string s[maxn];

char a[maxn][maxn] , b[maxm][maxm];

bool has[maxm][maxm][maxm][maxm];
int grundy[maxm][maxm][maxm][maxm];

int get(int x1 , int x2 , int y1 , int y2)
{
	if(x2 - x1 - 1 <= 0 || y2 - y1 - 1 <= 0)
		return 0;

	if(has[x1][x2][y1][y2])
		return grundy[x1][x2][y1][y2];

	bitset<300> adj;
	for(int i = 0; i < 300; i++)
		adj[i] = 0;

	for(int i = x1 + 1; i < x2; i++)
		for(int j = y1 + 1; j < y2; j++)
		{
			if(!b[i][j])
				continue;

			if(b[i][j] == 'L')
			{
				int nw = get(x1 , i , y1 , y2) ^ get(i , x2 , y1 , y2);
				adj[nw] = 1;
			}
			else if(b[i][j] == 'R')
			{
				int nw = get(x1 , x2 , y1 , j) ^ get(x1 , x2 , j , y2);
				adj[nw] = 1;
			}
			else
			{
				int nw = get(x1 , i , y1 , j) ^ get(x1 , i , j , y2) ^ get(i , x2 , y1 , j) ^ get(i , x2 , j , y2);
				adj[nw] = 1;
			}
		}

	for(int i = 0; ; i++)
		if(!adj[i])
		{
			grundy[x1][x2][y1][y2] = i;
			has[x1][x2][y1][y2] = 1;
			return i;
		}
}

int solve(int n , int m)
{
	memset(grundy , 0 , sizeof grundy);
	memset(has , 0 , sizeof has);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			b[i + j][i - j + maxn] = a[i][j];

	return get(0 , maxm - 1 , 0 , maxm - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] = '#' + s[i];
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if((i + j) % 2)
				a[i][j] = s[i][j];
			else
				a[i][j] = 0;
		}

	int res = solve(n , m);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if((i + j) % 2 == 0)
				a[i][j] = s[i][j];
			else
				a[i][j] = 0;
		}

	res ^= solve(n , m);
	if(res)
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;
}