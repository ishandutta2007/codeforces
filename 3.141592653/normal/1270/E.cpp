#include<cstdio>
#include<cstring>
int stk[1111111],top;
int x[1111111],y[1111111];
int n;
void convert(bool var)
{
	register int i; 
	if(var)for(i=1;i<=n;i++)x[i]++;
	int del=x[1]-y[1],sum=x[1]+y[1];
	x[1]=y[1]=0;
	for(i=2;i<=n;i++)
	{
		int t=x[i]-y[i],w=x[i]+y[i];
		x[i]=(t-del)>>1,y[i]=(w-sum)>>1;
	}
}
int main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]); 
	T:top=0;
	for(i=1;i<=n;i++)
		if((x[i]+y[i])&1)stk[++top]=i;
	if(top==n||(!top))
	{
		convert(top==n);
		goto T;
	}printf("%d\n",top);
	for(i=1;i<=top;i++)printf("%d ",stk[i]);
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/