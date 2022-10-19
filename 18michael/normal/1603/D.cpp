#include<bits/stdc++.h>
#define Mx 16
#define Mx2 100000
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int p_t=0,Test_num;
LL res;
int p[100002],mnp[100002];
LL s[100002];
LL f[18][100002],pre[100002][322],pre1[100002][322];
inline LL calc(int x,int y)
{
	if(!y)return 0;
	int z=x/((x/y)+1);
	return (z? (z<=x/z? pre[x][z]:pre1[x][x/z]):0)+s[x/y]*(y-z);
}
inline LL c(int l,int r)
{
	return calc(r,r)-calc(r,l-1);
}
inline void solve(int x,int l,int r,int L,int R)
{
	if(l>r)return ;
	int mid=((l+r)>>1),p=L;
	LL val=f[x-1][L]+c(L+1,mid);
	for(int i=L+1;i<=R && i<mid;++i)if((res=f[x-1][i]+c(i+1,mid))<val)val=res,p=i;
	f[x][mid]=val,solve(x,l,mid-1,L,p),solve(x,mid+1,r,p,R);
}
inline void init()
{
	s[1]=1;
	for(int i=2;i<=Mx2;++i)
	{
		if(!mnp[i])p[++p_t]=mnp[i]=i,s[i]=i-1;
		for(int j=1;j<=p_t && p[j]*i<=Mx2;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))
			{
				s[p[j]*i]=s[i]*p[j];
				break;
			}
			s[p[j]*i]=s[i]*(p[j]-1);
		}
	}
	for(int i=2;i<=Mx2;++i)s[i]+=s[i-1];
	for(int i=1;i<=Mx2;++i)
	{
		res=0;
		for(int j=1,k;j<=i;j=k+1)
		{
			k=(i/(i/j));
			res+=s[i/j]*(k-j+1);
			if(k<=i/k)pre[i][k]=res;
			else pre1[i][i/k]=res;
		}
	}
	for(int i=1;i<=Mx2;++i)f[0][i]=inf;
	for(int i=1;i<=Mx;++i)f[i][0]=inf,solve(i,1,Mx2,0,Mx2);
}
int main()
{
	init(),scanf("%d",&Test_num);
	for(int x,y;Test_num--;)
	{
		scanf("%d%d",&x,&y);
		if(y>Mx || x<(1<<y))printf("%d\n",x);
		else printf("%lld\n",f[y][x]);
	}
	return 0;
}