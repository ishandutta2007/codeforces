#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

int a[100005][2];
int n,d,p,q;;
int stk[1000005];

inline int cmp(const void *a,const void *b)
{
	return ((int*)a)[0]-((int*)b)[0];
}

int main()
{
	scanf("%d%d%d%d",&n,&d,&p,&q);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i][0]=x*p+y*q;
		a[i][1]=i;
	}
	qsort(a+1,n,sizeof(a[0]),cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]<=d)
		{
			d-=a[i][0];
			ans++;
			stk[ans]=a[i][1];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	printf("%d ",stk[i]);
	printf("\n");
	
	return 0;
}