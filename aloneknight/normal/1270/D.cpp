#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,k,m,a[N],b[N],s[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k+1;i++)
	{
		int nn=0,p,x;
		for(int j=1;j<=k+1;j++)if(j!=i)b[++nn]=j;
		printf("? ");
		for(int j=1;j<=k;j++)printf("%d%c",b[j],j==k?'\n':' ');
		fflush(stdout);
		scanf("%d%d",&p,&x);a[p]=x;s[p]++;
	}
	int p1=0,p2=0,t1=-1,t2=-1;
	for(int i=1;i<=n;i++)if(s[i])
	{
		if(!p1){p1=i;t1=s[i];}
		else{p2=i;t2=s[i];}
	}
	if(a[p1]>a[p2])swap(p1,p2),swap(t1,t2);
	printf("! %d\n",t2);
	return 0;
}