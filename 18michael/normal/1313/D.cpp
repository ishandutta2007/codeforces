#include<cstdio>
#include<algorithm>
#define Mx 256
#define inf 100000000
using namespace std;
int n,m,k,a_t=0,st_t=8,now=0;
int one[262]={},u[8]={};
int f[200002][262]={};
struct aaa
{
	int pos,opt,num;
}a[200002];
inline bool cmp(aaa a,aaa b)
{
	return a.pos==b.pos? (a.opt<b.opt):(a.pos<b.pos);
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	for(int i=1;i<Mx;++i)one[i]=one[(i>>1)]+(i&1);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),a[++a_t]=(aaa){x,1,i},a[++a_t]=(aaa){y+1,-1,i};
	sort(a+1,a+a_t+1,cmp);
	for(int i=0;i<=a_t;++i)
		for(int j=1;j<Mx;++j)
			f[i][j]=-inf;
	for(int i=1,v;i<=a_t;++i)
	{
		if(a[i].opt==1)
		{
			for(int j=0;j<8;++j)
				if(!u[j])
				{
					u[j]=a[i].num,v=j;
					break;
				}
		}
		else
		{
			for(int j=0;j<k;++j)
				if(u[j]==a[i].num)
				{
					u[j]=0,v=j;
					break;
				}
		}
		now^=(1<<v);
		for(int j=now;;j=((j-1)&now))
		{
			if(a[i].opt==1)
			{
				if(j&(1<<v))f[i][j]=max(f[i][j],f[i-1][(j^(1<<v))]+(one[(j^(1<<v))]&1)*(a[i].pos-1-a[i-1].pos)+(one[j]&1));
				else f[i][j]=max(f[i][j],f[i-1][j]+(one[j]&1)*(a[i].pos-a[i-1].pos));
			}
			else
			{
				if(!(j&(1<<v)))
				{
					f[i][j]=max(f[i][j],f[i-1][j]+(one[j]&1)*(a[i].pos-a[i-1].pos));
					f[i][j]=max(f[i][j],f[i-1][(j^(1<<v))]+(one[(j^(1<<v))]&1)*(a[i].pos-1-a[i-1].pos)+(one[j]&1));
				}
			}
			if(!j)break;
		}
	}
	printf("%d",f[a_t][0]);
	return 0;
}