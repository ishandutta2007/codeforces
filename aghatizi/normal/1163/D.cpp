#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 1e3 + 20;
const int maxm = 50 + 20;
const int maxs = 30;
 
int nxt[2][maxm][maxs];
 
int f[2][maxm] , dp[maxn][maxm][maxm];
 
string a , s[2];
 
void smax(int &x , int y)
{
	if(x < y)
		x = y;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> a >> s[0] >> s[1];
 
	int n = a.size();
	for(int ind = 0; ind < 2; ind++)
	{
		int n = s[ind].size();
 
		int k = 0;
		for(int i = 1; i < n; i++)
		{
			while(k && s[ind][k] != s[ind][i])
				k = f[ind][k];
 
			k += (s[ind][k] == s[ind][i]);
			f[ind][i + 1] = k;
		}
 
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < maxs; j++)
			{
				if(i == n || s[ind][i] != j + 'a')
					nxt[ind][i][j] = nxt[ind][f[ind][i]][j];
				else
					nxt[ind][i][j] = i + 1;
			}
	}
 
	memset(dp , -63 , sizeof dp);
	dp[0][0][0] = 0;
 
	int res = -1e9;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= (int)s[0].size(); j++)
			for(int k = 0; k <= (int)s[1].size(); k++)
			{
				if(j == (int)s[0].size())
					dp[i][j][k]++;
				if(k == (int)s[1].size())
					dp[i][j][k]--;
 
				if(i == n)
				{
					smax(res , dp[i][j][k]);
					continue;
				}
 
				int l = 0 , r = 26;
				if(a[i] != '*')
					l = a[i] - 'a' , r = l + 1;
 
				for(int x = l; x < r; x++)
					smax(dp[i + 1][nxt[0][j][x]][nxt[1][k][x]] , dp[i][j][k]);
			}
 
	cout << res << endl;
}