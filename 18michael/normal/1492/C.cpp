#include<cstdio>
int n,m,ans=0;
char s[200002],t[200002];
int pre[200002],suf[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	read(n),read(m),scanf("%s",s+1),scanf("%s",t+1);
	for(int i=1,j=1;i<=n && j<=m;++i)if(s[i]==t[j])pre[j]=i,++j;
	for(int i=n,j=m;i && j;--i)if(s[i]==t[j])suf[j]=i,--j;
	for(int i=1;i<=m;++i)ans=max(ans,suf[i+1]-pre[i]);
	return 0&printf("%d",ans);
}