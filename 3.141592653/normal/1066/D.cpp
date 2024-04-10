#include<cstdio>
#include<algorithm>
typedef long long ll;
int a[1111111];int n,m,k;
ll s[1111111],nxt[1111111];
inline int half(int x)
{
	int l=x,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(s[mid]-s[x-1]<=k)l=mid;
		else r=mid;
	}return r;
}
int fa[222222][22];
inline int getfa(int x,int k)
{
	int i=0;
	while(k)
	{
		if(k&1)x=fa[x][i];i++,k>>=1;
	}return x;
}
void exec()
{
	scanf("%d%d%d",&n,&m,&k);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(i=n;i;i--)nxt[i]=half(i);
	nxt[n+1]=n+1;
	for(i=n+1;i;i--)
		fa[i][0]=nxt[i];
	for(i=1;i<20;i++)
		for(ii=1;ii<=n+1;ii++)fa[ii][i]=fa[fa[ii][i-1]][i-1];
	int ans=0;
	i=1;
	while(getfa(i,m)<=n)
	{i++;if(i>n)break;}
	ans=n+1-i;
	printf("%d\n",ans);
}
int main()
{
	int T;
	//scanf("%d",&T);
	T=1;
	while(T--)exec();
}