#include<cstdio>
#define Mx 16
#define inf 0x3f3f3f3f
int n,q;
int a[100002];
struct aaa
{
	int g,mn,cnt;
}f[100002][18],ans;
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
inline aaa merge(aaa a,aaa b)
{
	a.g=gcd(a.g,b.g);
	if(a.mn>b.mn)a.mn=b.mn,a.cnt=b.cnt;
	else if(a.mn==b.mn)a.cnt+=b.cnt;
	return a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[i][0]=(aaa){a[i],a[i],1};
	for(int i=1;i<=Mx;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			f[j][i]=merge(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	scanf("%d",&q);
	for(int x,y,z;q--;)
	{
		scanf("%d%d",&x,&y),z=y-x+1,ans=(aaa){0,inf,0};
		for(int i=Mx;~i;--i)if(x+(1<<i)-1<=y)ans=merge(ans,f[x][i]),x+=(1<<i);
		printf("%d\n",z-(ans.g==ans.mn? ans.cnt:0));
	}
	return 0;
}