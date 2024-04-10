#include<cstdio>
#include<cstring>
#define inf 100000
int ls,lt,la;
int f[100002]={},g[100002],nx[100002];
char s[100002],t[100002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void init()
{
	scanf("%s%s",s,t),ls=strlen(s),lt=strlen(t),nx[0]=0;
	for(int i=1,j;i<lt;++i)
	{
		for(j=nx[i-1];j && t[j]!=t[i];j=nx[j-1]);
		if(t[j]!=t[i])nx[i]=0;else nx[i]=j+1;
	}
}
inline bool check(int x,int y,int z)
{
	for(int i=y;i<z;++i)
		if(s[x+i]!='?' && s[x+i]!=t[i])
			return 0;
	return 1;
}
int main()
{
	init();
	for(int i=0;i<ls;++i)g[i]=-inf;
	for(int i=lt-1;i<ls;++i)
	{
		la=lt;
		for(int j=nx[lt-1];;j=nx[j-1])
		{
			if(!check(i-lt+1,j,la))break;la=j;
			if(!j){g[i]=max(g[i],(i>=lt? f[i-lt]:0)+1);break;}
			g[i]=max(g[i],g[i-(lt-j)]+1);
		}
		f[i]=max(f[i-(i>0)],g[i]);
	}
	printf("%d",f[ls-1]);
	return 0;
}