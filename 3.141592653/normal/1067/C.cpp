#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int x[11111],y[11111],tt;
void inp(int a,int b){x[++tt]=a,y[tt]=b;}
void ins(int a,int b)
{
	x[++tt]=a,y[tt]=b;
	if(a>1)x[++tt]=b,y[tt]=a;
}
int main()
{
	int n;
	scanf("%d",&n);
	register int i;
	inp(-1,-1);
	for(i=0;i<=1000;i++)
	{
		ins(i,i&1);
		if(i&1)inp(-1,i),inp(i,-1);
	}
	for(i=1;i<=n;i++)printf("%d %d\n",x[i],y[i]);
}
/*
Please don't let me down.
*/