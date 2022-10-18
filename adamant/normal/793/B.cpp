#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;

int ok[maxn][maxn];
int nok[maxn][maxn];
string s[maxn];

void make(int i, int j)
{
	for(int k = 0; k < maxn; k++)
		if(i - k < 0 || s[i - k][j] == '*')
			break;
		else
			nok[i - k][j] = 1;
	for(int k = 0; k < maxn; k++)
		if(i + k >= maxn || s[i + k][j] == '*')
			break;
		else
			nok[i + k][j] = 1;
	for(int k = 0; k < maxn; k++)
		if(j - k < 0 || s[i][j - k] == '*')
			break;
		else
			nok[i][j - k] = 1;
	for(int k = 0; k < maxn; k++)
		if(j + k >= maxn || s[i][j + k] == '*')
			break;
		else
			nok[i][j + k] = 1;
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'S')
				ok[i][j] = 1;
	}
	for(int z = 0; z < 2; z++)
	{
		memcpy(nok, ok, sizeof(ok));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(ok[i][j])
					make(i, j);
		memcpy(ok, nok, sizeof(nok));
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'T')
			{
				memset(nok, 0, sizeof(nok));
				make(i, j);
				break;
			}
			
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(ok[i][j] && nok[i][j])
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}