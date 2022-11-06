#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxm = 11;

int a[maxm][maxn] , sz[maxm][maxn] , pos[maxm][maxn];

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for(int i = 0; i < n; i++)
		pos[0][a[0][i]] = i;

	for(int i = 1; i < m; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = pos[0][a[i][j]];

	for(int i = 0; i < n; i++)
		a[0][i] = i;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			pos[i][a[i][j]] = j;

	for(int i = 0; i < m; i++)
	{
		int last = 0;

		
		for(int j = 0; j < n; j++)
		{
			if(!j || a[i][j] == a[i][j - 1] + 1)
				continue;
			else
			{
				for(int k = last; k < j; k++)
					sz[i][a[i][k]] = j - k;

				last = j;
			}
		}

		for(int k = last; k < n; k++)
			sz[i][a[i][k]] = n - k;
	}

	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		int Mn = 1e9;

		for(int j = 0; j < m; j++)
			Mn = min(Mn , sz[j][i]);

		res += Mn;
	}

	cout << res << endl;
}