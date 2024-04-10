#include <bits/stdc++.h>
using namespace std;

const int N = 10;
bool g[N][N];
int rep[N];
vector<int> ch[N];
int nr[N];
bool vis[N];
int n;

vector<int> sorted;

void topsort(int v)
{
	static int time = 0;
	vis[v] = true;
	for(int i = 0; i < n; i++)
		if(rep[i] == i && g[v][i] && !vis[i]) topsort(i);
	nr[v] = time++;
	sorted.push_back(v);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for(int i = 0; i < n; i++)
		g[i][i] = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				g[j][k] |= g[j][i] && g[i][k];
	
	for(int i = 0; i < n; i++)
	{
		rep[i] = i;
		for(int j = 0; j < i; j++)
			if(g[i][j] && g[j][i])
			{
				rep[i] = j;
				break;
			}
		ch[rep[i]].push_back(i);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(g[i][j]) g[rep[i]][rep[j]] = true;
	for(int i = 0; i < n; i++)
		if(rep[i] == i && !vis[i])
			topsort(i);
	reverse(sorted.begin(), sorted.end());
	int m = sorted.size();
	printf("%d %d %d\n", 2 * n, 3, 5 * m);
	for(int i: sorted)
	{
		bool e[N];
		for(int j = 0; j < n; j++)
			e[j] = rep[j] == j && g[i][j] && nr[i] > nr[j];
		for(int k = 0; k < 2; k++)
		{
			for(int j = 0; j < n; j++)
				printf(".#");
			puts("");
			
			for(int j = 0; j < n; j++)
			{
				putchar(j == i || e[j] ? '.' : '#');
				putchar('#');
			}
			puts("");
			
			for(int j = 0; j < 2 * n; j++)
			{
				if(k == 0 || j >= ch[i].size()) putchar('.');
				else printf("%d", ch[i][j] + 1);
			}
			puts("");
			
			puts("");
		}
		
		for(int j = 0; j < n; j++)
		{
			putchar(j == i ? '#' : '.');
			putchar('#');
		}
		puts("");
		
		for(int j = 0; j < 2 * n; j++)
			putchar('#');
		puts("");	
		
		for(int j = 0; j < 2 * n; j++)
			putchar('#');
		puts("");
		
		puts("");
		
		for(int a = 0; a < 2; a++)
		{
			for(int b = 0; b < 3; b++)
			{
				for(int j = 0; j < 2 * n; j++)
					putchar('.');
				puts("");
			}
			puts("");
		}
	}
}