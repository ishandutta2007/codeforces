#include<bits/stdc++.h>
#define Mx 58
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,t,cnt=0,cnt1;
LL mx=0;
int id[100002],tmp[100002];
LL a[100002];
int f[62][100002];
inline void upd(int &x,int y)
{
	if(y<x)x=y;
}
inline void Sort(int x)
{
	t=0;
	for(int i=1;i<=n;++i)tmp[i]=id[i];
	for(int i=1;i<=n;++i)if((a[tmp[i]]>>x)&1)id[++t]=tmp[i];
	for(int i=1;i<=n;++i)if(!((a[tmp[i]]>>x)&1))id[++t]=tmp[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=Mx;++i)for(int j=0;j<=n;++j)f[i][j]=inf;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),id[i]=i,mx=max(mx,a[i]);
	for(int i=1;i<=n;++i)a[i]=mx-a[i],cnt+=(a[i]&1);
	Sort(0),upd(f[0][0],cnt),upd(f[0][cnt],n-cnt);
	for(int i=0;i<Mx;++i)
	{
		Sort(i),cnt=cnt1=0;
		for(int j=1;j<=n;++j)cnt+=((a[j]>>(i+1))&1);
		for(int j=0;j<=n;++j)
		{
			if(j)cnt+=((a[id[j]]>>(i+1))&1? -1:1),cnt1+=((a[id[j]]>>(i+1))&1);
			upd(f[i+1][cnt1],f[i][j]+cnt),upd(f[i+1][cnt1+cnt],f[i][j]+n-cnt);
		}
	}
	return 0&printf("%d",f[Mx][0]);
}