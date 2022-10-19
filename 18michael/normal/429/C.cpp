#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt=0,cnt1,Mx;bool ok=0;
int a[26],lg[2048],sum[2048]={},one[2048];
bool f[12][2048][24]={};
inline bool cmp(int x,int y)
{
	return x>y? 1:0;
}
inline int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	scanf("%d",&n),f[0][0][0]=1,lg[0]=one[0]=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),cnt+=(a[i]==1),ok|=(a[i]==2);
	if(cnt<=n/2 || ok)return 0&puts("NO");
	if(n==1)return 0&puts(a[1]==1? "YES":"NO");
	sort(a+1,a+n+1,cmp),Mx=(1<<(cnt1=n-cnt))-1;
	for(int i=1,i1;i<=Mx;++i)lg[i]=lg[i>>1]+1,one[i]=one[i>>1]+(i&1),i1=lowbit(i),sum[i]=sum[i^i1]+a[lg[i1]];
	for(int i=0;i<cnt1;++i)
		for(int j=0;j<Mx;++j)
			for(int k=0,k1=(Mx^j);k<=cnt;++k)
				if(f[i][j][k])
					for(int l=k1,l1;;(--l)&=k1)
					{
						if((l1=a[i+1]-sum[l]-1)>=0 && k+l1<=cnt && one[l]+l1>=2)f[i+1][j|l][k+l1]=1;
						if(!l)break;
					}
	return 0&puts(f[cnt1][Mx^1][cnt]? "YES":"NO");
}