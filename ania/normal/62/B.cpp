#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 100100

char s[maxn], cur[2*maxn];
int distl[maxn][26], distr[maxn][26];

int main()
{
	int n,m,k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < k; i++) s[i] -= 'a';
	for(int j = 0; j < 26; j++) distl[0][j] = 1e9;
	for(int i = 0; i < k; i++)
	{
		if(i > 0) for(int j = 0; j < 26; j++) distl[i][j] = distl[i-1][j] + 1;
		distl[i][s[i]] = 0;
	}
	for(int j = 0; j < 26; j++) distr[k-1][j] = 1e9;
	for(int i = k-1; i >= 0; i--)
	{
		if(i < k-1) for(int j = 0; j < 26; j++) distr[i][j] = distr[i+1][j] + 1;
		distr[i][s[i]] = 0;
	}
	for(int q = 0; q < n; q++)
	{
		scanf("%s", cur);
		for(m = 0; cur[m]; m++) ;
		long long res = 0;
		for(int i = 0; i < m; i++)
		{
			int x;
			if(i >= k) x = distl[k-1][cur[i]-'a'] + i-k+1;
			else x = min(distl[i][cur[i]-'a'], distr[i][cur[i]-'a']);
			if(x > 1e8) res += m;
			else res += x;
		}
		cout << res << endl;
	}
}