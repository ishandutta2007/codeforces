#include<cstdio>
#define R register
int n,m,k,ans;
int a[102][102],b[102][102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline int check(int x,int y)
{
	int cnt;
	for(R int i=1;i<=n;++i)
		if(i!=x)
		{
			cnt=0;
			for(R int j=1;j<=m;++j)
				if(a[x][j]!=a[i][j])
					++cnt;
			y-=min(cnt,m-cnt);
		}
	return y;
}
inline void dfs(int x,int y)
{
	if(y<=ans)return ;
	if(x>m)
	{
		ans=max(ans,check(1,y));
		return ;
	}
	dfs(x+1,y);
	if(y)a[1][x]^=1,dfs(x,y-1),a[1][x]^=1;
}
int main()
{
	read(n),read(m),read(k),ans=-1;
	for(R int i=1;i<=n;++i)
		for(R int j=1;j<=m;++j)
			read(a[i][j]);
	if(n<m)
	{
		for(R int i=1;i<=n;++i)
			for(R int j=1;j<=m;++j)
				b[i][j]=a[i][j];
		for(R int i=1;i<=n;++i)
			for(R int j=1;j<=m;++j)
				a[j][i]=b[i][j];
		swap(n,m);
	}
	if(n>k)for(R int i=1;i<=k+1;++i)ans=max(ans,check(i,k));
	else dfs(1,k);
	if(ans<0)puts("-1");
	else printf("%d\n",k-ans);
	return 0;
}