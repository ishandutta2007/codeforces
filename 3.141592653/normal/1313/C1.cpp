#include<cstdio>
#include<iostream>
#include<cmath>
const double PI=(acos(-1));
#include<queue>
#include<map>
#include<cstring>
#include<cstdlib>
int a[1111111];
int b[1111111];
int n;
using namespace std;
void print(int p)
{
	b[p]=a[p];
	register int i;
	for(i=p-1;i;i--)b[i]=min(a[i],b[i+1]);
	for(i=p+1;i<=n;i++)b[i]=min(a[i],b[i-1]);
	for(i=1;i<=n;i++)printf("%d ",b[i]);
	puts("");
}
typedef long long ll;
int stkl[1111111],stkr[1111111],stk[1111111],top;
ll ans=0,sum;
int plc=1;
void insert(int x,int p)
{
	int l=p,r=p;
	while(top&&x<stk[top])
	{
		int sz=stkr[top]-stkl[top]+1;
		sum-=sz*1ll*stk[top],l=stkl[top],top--;
	}stk[++top]=x,stkl[top]=l,stkr[top]=r;
	sum+=(r-l+1)*1ll*x;
}
void clr()
{top=0;sum=0;}
ll val[1111111];
void exec()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		insert(a[i],i),val[i]=sum;
	clr();
	for(i=n;i;i--)insert(a[i],n-i+1),val[i]+=sum-a[i];
	for(i=1;i<=n;i++)
		if(val[i]>ans)ans=val[i],plc=i;
	print(plc);
}
signed main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}