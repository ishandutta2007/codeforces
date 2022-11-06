/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 5009, M = 1e6 + 9;
//int a[N][N];
char s[N][N];	
int n, cnt;
vector<int> G[M];
inline void dfs(int col)
{
	int bla = cnt + 1, whi = cnt + 2;
	if(G[col].size() <= 1) return ;
	for (int i = 1; i < G[col].size(); i++)
		if(s[G[col][0]][G[col][i]] == '1') G[bla].push_back(G[col][i]);
		else G[whi].push_back(G[col][i]);
	for (int i = 0; i < G[bla].size(); i++)
		for (int j = 0; j < G[whi].size(); j++)
			if(s[G[bla][i]][G[whi][j]] == '1')
			{
				printf("%d %d %d\n", G[col][0], G[bla][i], G[whi][j]);
				exit(0);
			}
	cnt += 2;
	dfs(bla);
	dfs(whi);
	return ;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	cnt = 1;
	for (int i = 1; i <= n; i++) G[cnt].push_back(i);	
	dfs(1);
	puts("-1");
	return 0;
}