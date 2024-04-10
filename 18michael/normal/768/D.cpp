#include<cstdio>
#include<algorithm>
#define Mx 8000
using namespace std;
int k,q;
double f[8002][1002];
struct aaa
{
	int q,id,ans;
}a[1002];
inline bool cmp(aaa a,aaa b)
{
	return a.q<b.q? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return a.id<b.id? 1:0;
}
inline double dp(int x,int y)
{
	if(x<0 || y<0)return 0;
	if(f[x][y]>=0)return f[x][y];
	f[x][y]=1.0*y/k*dp(x-1,y-1)+1.0*(k-y)/k*dp(x-1,y);
	return f[x][y];
}
inline void init()
{
	for(int i=0;i<=Mx;++i)
	{
		f[i][0]=1;
		for(int j=1;j<=k;++j)
			f[i][j]=-1;
	}
	for(int i=0;i<=Mx;++i)f[i][k]=dp(i,k);
}
int main()
{
	scanf("%d%d",&k,&q),init();
	for(int i=1;i<=q;++i)scanf("%d",&a[i].q),a[i].id=i;
	sort(a+1,a+q+1,cmp);
	for(int i=1,j=1;i<=q;++i)
	{
		while(f[j][k]*2000<a[i].q)++j;
		a[i].ans=j;
	}
	sort(a+1,a+q+1,cmp1);
	for(int i=1;i<=q;++i)printf("%d\n",a[i].ans);
	return 0;
}