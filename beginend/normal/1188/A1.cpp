#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,deg[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		deg[x]++;deg[y]++; 
	}
	for (int i=1;i<=n;i++) if (deg[i]==2) {puts("NO");return 0;}
	puts("YES");
	return 0;
}