#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300;
struct node
{
	int mid,l;
}a[N];
int n,cnt,i,j,k,x,y,f[N][N][2],ans;
bool cmp(node a,node b)
{
	return a.mid<b.mid;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].mid,&a[i].l);
	sort(a+1,a+1+n,cmp);
	a[0].mid=-200000000;
	f[0][0][0]=f[0][0][1]=0;
	for(i=0;i<=n;++i)
		for(j=0;j<=i;++j)
		{
			f[i+1][j][0]=max(f[i+1][j][0],f[i][j][0]);
			f[i+1][j][1]=max(f[i+1][j][1],f[i][j][1]);
			for(k=i+1,x=y=-200000000;k<=n;++k)
			{
				f[k][k][1]=max(f[k][k][1],f[i][j][0]+a[k].l);
				if(x>a[k].mid)
					f[k][y][1]=max(f[k][y][1],f[i][j][0]+x-max(a[k].mid-a[k].l,a[j].mid));
				else
					f[k][k][0]=max(f[k][k][0],f[i][j][0]+a[k].mid-max(a[k].mid-a[k].l,a[j].mid));
				if(a[k].mid+a[k].l>x)
				{
					x=a[k].mid+a[k].l;
					y=k;
				}
			}
			for(k=i+1,x=y=-200000000;k<=n;++k)
			{
				if(a[k].mid+a[k].l<=a[j].mid+a[j].l)
					f[k][j][1]=max(f[k][j][1],f[i][j][1]);
				else
					f[k][k][1]=max(f[k][k][1],f[i][j][1]+a[k].mid+a[k].l-max(a[j].mid+a[j].l,a[k].mid));
				if(x>a[k].mid)
					f[k][y][1]=max(f[k][y][1],f[i][j][1]+x-max(a[k].mid-a[k].l,a[j].mid+a[j].l));
				else
					f[k][k][0]=max(f[k][k][0],f[i][j][1]+a[k].mid-max(a[k].mid-a[k].l,a[j].mid+a[j].l));
				if(a[k].mid+a[k].l>x)
				{
					x=a[k].mid+a[k].l;
					y=k;
				}
			}
		}
	for(j=1;j<=n;++j)
		ans=max(ans,max(f[n][j][0],f[n][j][1]));
	printf("%d",ans);
	return 0;
}