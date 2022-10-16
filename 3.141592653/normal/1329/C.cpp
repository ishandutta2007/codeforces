#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
#define inlien inline
#define retrun return
#define cpnst const
int n,g,h,N,M;
char s[2211111];
ll a[2211111],siz[2211111],tiz[2211111];
bool isl[2211111];
void kick(int x,int SIZ)
{
	//printf("%d %d %d\n",x,SIZ,siz[x]);
	int L=x<<1,R=L|1;
	siz[x]--;
	if(!(a[L]||a[R]))a[x]=0;
	else
	{
		if(a[L]>a[R])a[x]=a[L],kick(L,SIZ>>1);
		else a[x]=a[R],kick(R,SIZ>>1);
	}if(siz[x]==SIZ)isl[x]=1;
	if(!isl[x])
	{
		if(!(a[L]||a[R])){isl[x]=!siz[x];goto T;}
		if(a[L]>a[R]){if(isl[L])isl[x]=1;}
		else{if(isl[R])isl[x]=1;}
	}T:;
	//printf("%d %d\n",x,isl[x]);
}
int stk[2222222],top;
void exec()
{
	register int i,ii,iii;
	scanf("%d%d",&h,&g),N=(1<<h),M=(1<<g);
	top=0;
	for(i=1;i<(N<<1);i++)a[i]=siz[i]=tiz[i]=isl[i]=0;
	siz[0]=(N<<1)-1;
	for(i=1;i<N;i++)siz[i]=siz[i>>1]>>1;
	tiz[0]=(M<<1)-1;
	for(i=1;i<M;i++)tiz[i]=tiz[i>>1]>>1;
	long long ans=0;
	for(i=1;i<N;i++)scanf("%d",a+i),ans+=a[i];
	//for(i=1;i<M;i++)printf("%d ",tiz[i]);puts("");
	for(i=1;i<N;i++)
		while(!isl[i])ans-=a[i],kick(i,tiz[i]),stk[++top]=i;
	printf("%lld\n",ans);
	for(i=1;i<=top;i++)printf("%d ",stk[i]);puts("");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}