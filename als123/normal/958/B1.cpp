#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int y,next;
}a[2010];int len=0,last[1010];
int n,d[1010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		d[x]++;d[y]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(d[i]==1) ans++;
	printf("%d\n",ans);
}