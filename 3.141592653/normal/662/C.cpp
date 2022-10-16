#include<cstdio>
#include<cstring>
typedef long long ll;
int n,m,k;
ll F[1<<20],G[1<<20];
char str[22][1<<22];
inline int rd(int ii,int i=1)
{
	if(!str[i][ii])return 0;
	return rd(ii,i+1)<<1|(str[i][ii]&1);
}
void FWT(ll*a,int tp)
{
	register int i,ii,iii;
	for(i=1;i<k;i<<=1)
		for(ii=0;ii<k;ii+=(i<<1))
			for(iii=0;iii<i;iii++)
			{
				int px=ii+iii,py=i+ii+iii;
				ll vx=a[px]+a[py],vy=a[px]-a[py];
				if(tp==-1)vx/=2,vy/=2;
				a[px]=vx,a[py]=vy;
			}
} 
int main()
{
	scanf("%d%d",&n,&m),k=1<<n;
	register int i;
	for(i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(i=1;i<=m;i++)
		G[rd(i)]++;
	for(i=0;i<k;i++)F[i]=F[i>>1]+(i&1);
	for(i=0;i<k;i++)if(F[i]*2>n)F[i]=n-F[i];
	FWT(F,1),FWT(G,1);
	for(i=0;i<k;i++)F[i]*=G[i];
	FWT(F,-1);
	int ans=1e9;
	for(i=0;i<k;i++)
		if(F[i]<ans)ans=F[i];
	printf("%d\n",ans);
}
/*
Every little step contributes in constructing what is called the great.
*/