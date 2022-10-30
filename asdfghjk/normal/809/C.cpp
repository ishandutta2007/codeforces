#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
struct node
{
	int num1,num2;
}f[35][2][2][2];
int q,l1,r1,l2,r2,ans,i,n,m,p;
bool v[35][2][2][2];
void dfs(int i,bool t1,bool t2,bool t3)
{
	if(v[i+1][t1][t2][t3])
		return;
	if(i<0)
	{
		f[i+1][t1][t2][t3]=(node){1,0};
		return;
	}
	int up1=(!t1?1:n>>i&1),up2=(!t2?1:m>>i&1),up3=(!t3?1:p>>i&1),w=0,u=0;
	for(int j=0;j<=up1;++j)
		for(int k=0;k<=up2;++k)
			if((j^k)<=up3)
			{
				dfs(i-1,t1&&j==up1,t2&&k==up2,t3&&(j^k)==up3);
				w=(w+f[i][t1&&j==up1][t2&&k==up2][t3&&(j^k)==up3].num1)%md;
				if(j)
					u=(u+(1ll<<i)*f[i][t1&&j==up1][t2&&k==up2][t3&&(j^k)==up3].num1)%md;
				u=(u+f[i][t1&&j==up1][t2&&k==up2][t3&&(j^k)==up3].num2)%md;
			}
	f[i+1][t1][t2][t3]=(node){w,u};
	v[i+1][t1][t2][t3]=true;
}
int work(int x,int y,int K)
{
	if(x<=0||y<=0||K<=0)
		return 0;
	n=K-1,m=y-1,p=x-1;
	for(int i=0;i<=32;++i)
		for(int j=0;j<=1;++j)
			for(int k=0;k<=1;++k)
				for(int x=0;x<=1;++x)
					v[i][j][k][x]=false;
	dfs(30,true,true,true);
	return (f[31][true][true][true].num2+f[31][true][true][true].num1)%md;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d%d",&l1,&l2,&r1,&r2,&i);
		ans=(1ll*work(r1,r2,i)-work(l1-1,r2,i)-work(r1,l2-1,i)+work(l1-1,l2-1,i)+2ll*md)%md;
		printf("%d\n",ans);
	}
	return 0;
}