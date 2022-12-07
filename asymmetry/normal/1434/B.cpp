#include <bits/stdc++.h>

using namespace std;

int n, l, x, y;
int odp[200001];
int po[200001];
int p[200001];
int t[200001];
int ls[200001][2];
char s[6];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n*2; ++i)
	{
		scanf("%s", s);
		if(s[0]=='-')
		{
			scanf("%d", &t[i]);
			po[t[i]]=i;
		}
		else
		{
			++l;
			t[i]=0;
			p[i]=l;
		}
		ls[i][0]=i-1;
		ls[i][1]=i+1;
	}
	t[0]=1e9;
	for(int i=1; i<=n; ++i)
	{
		x=po[i];
		y=ls[x][0];
		if(t[y])
		{
			printf("NO\n");
			return 0;
		}
		odp[p[y]]=i;
		ls[ls[y][0]][1]=ls[y][1];
		ls[ls[y][1]][0]=ls[y][0];
		ls[ls[x][0]][1]=ls[x][1];
		ls[ls[x][1]][0]=ls[x][0];
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i)
	{
		printf("%d ", odp[i]);
	}
	return 0;
}