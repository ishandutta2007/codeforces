#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int a[1111111];
void decide(int l,int r,int d)
{for(register int i=l;i<=r;i++)a[i]=d;}
void ask(int l,int r)
{printf("? %d %d\n",l,r),fflush(stdout);}
void solve(int l,int r)
{
	if(l>r)return;
	ask(l,r);
	int mid=(l+r)>>1,x,f;
	scanf("%d%d",&x,&f);
	if(l+f-1>=r-f+1)decide(r-f+1,l+f-1,x),solve(l,r-f),solve(l+f,r);
	else solve(l,mid),solve(mid+1,r);
}
void answ(int n)
{
	register int i;
	printf("! ");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);puts("");
	fflush(stdout);
}
int main()
{int n;scanf("%d",&n),solve(1,n),answ(n);}
/*
Just go for it.
*/