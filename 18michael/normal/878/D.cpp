#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
int n,k,q,Mx,tot,t;
int a[100002][14],id[100002][14];
bitset<4096> bs[100022];
inline bool cmp(int x,int y)
{
	return a[t][x]<a[t][y]? 1:0;
};
int main()
{
	scanf("%d%d%d",&n,&k,&q),Mx=(1<<k),tot=k;
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<Mx;++j)bs[i][j]=((j>>(i-1))&1);
		for(int j=1;j<=n;++j)scanf("%d",&a[j][i]),id[j][i]=i;
	}
	for(int i=1;i<=n;++i)t=i,sort(id[i]+1,id[i]+k+1,cmp);
	for(int x,y;q--;)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)bs[++tot]=(bs[x]|bs[y]);
		else if(t==2)bs[++tot]=(bs[x]&bs[y]);
		else
		{
			t=0;
			for(int j=k;j;--j)
				if(bs[x][t|=(1<<(id[y][j]-1))])
				{
					printf("%d\n",a[y][id[y][j]]);
					break;
				}
		}
	}
	return 0;
}