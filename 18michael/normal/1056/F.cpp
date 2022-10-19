#include<cstdio>
#include<algorithm>
#define eps 1e-4
#define eps1 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int n,sum,Test_num,ans;
double c,t,l,r,mid1,mid2;
int id[102],a[102],p[102];
double pw[102];
double f[102][1002];
inline bool cmp(int x,int y)
{
	return a[x]>a[y]? 1:0;
}
int main()
{
	scanf("%d",&Test_num),pw[0]=1,f[0][0]=0;
	for(int i=1;i<=100;++i)pw[i]=pw[i-1]*0.9;
	while(Test_num--)
	{
		scanf("%d%lf%lf",&n,&c,&t),ans=sum=0;
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&p[i]),id[i]=i,sum+=p[i];
		sort(id+1,id+n+1,cmp);
		for(int i=0;i<=n;++i)
			for(int j=sum;j;--j)
				f[i][j]=inf;
		sum=0;
		for(int i=1;i<=n;++i)
		{
			sum+=p[id[i]];
			for(int j=i;j;--j)
				for(int k=sum;k>=p[id[i]];--k)
					f[j][k]=min(f[j][k],f[j-1][k-p[id[i]]]+a[id[i]]/pw[j]);
		}
		for(int k=sum;k && !ans;--k)
			for(int j=1;j<=n;++j)
			{
				for(l=0,r=t;l+eps<r;)
				{
					mid1=(l+r)/2-eps1,mid2=(l+r)/2+eps1;
					if(mid1+f[j][k]/(1+c*mid1)>mid2+f[j][k]/(1+c*mid2))l=mid1;
					else r=mid2;
				}
				if(mid1+10*j+f[j][k]/(1+c*mid1)<=t)
				{
					ans=k;
					break;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}