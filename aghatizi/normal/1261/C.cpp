#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

vector<int> sum[maxn] , ker[maxn];

string s[maxn];

vector<int> can[maxn] , shit[maxn];

int n , m;

inline int get(int x1 , int y1 , int x2 , int y2)
{
	if(x1 <= 0 || y1 <= 0 || x2 > n || y2 > m)
		return -1000;

	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

bool check(int k)
{
	for(int i = k + 1; i <= n - k; i++)
		for(int j = k + 1; j <= m - k; j++)
			if(s[i - 1][j - 1] == 'X' && !get(i - k , j - k , i + k , j + k))
			{
				can[i - k][j - k]++;
				can[i - k][j + k + 1]--;
				can[i + k + 1][j - k]--;
				can[i + k + 1][j + k + 1]++;
				shit[i][j] = 1;
			}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			ker[i][j] = ker[i - 1][j] + ker[i][j - 1] - ker[i - 1][j - 1] + can[i][j];
			can[i][j] = 0;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(s[i - 1][j - 1] == 'X' && !ker[i][j])
				return 0;
			if(s[i - 1][j - 1] == '.' && ker[i][j])
				return 0;
		}

	return 1;

}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		s[i].resize(m);
		scanf("%s", s[i].begin());
	}

	for(int i = 0; i <= n + 2; i++)
		sum[i].resize(m + 5) , can[i].resize(m + 5) , shit[i].resize(m + 5) , ker[i].resize(m + 5);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (s[i][j] == '.');

	int l = 0 , r = min(n , m) + 5;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if(check(m))
			l = m;
		else
			r = m;
	}

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			shit[i][j] = 0;

	check(l);
	printf("%d\n", l);
	for(int i = 1; i <= n; i++, printf("\n"))
		for(int j = 1; j <= m; j++)
		{
			if(shit[i][j])
				printf("X");
			else
				printf(".");
		}
}