#include<cstdio>
#include<cstring>
int n;
char mp[1111][1111];
int fa[1111],vs[1111];
int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
void merge(int x,int y){x=rt(x),y=rt(y);if(x^y)fa[x]=y,vs[y]=1;}
typedef unsigned int unt;
unt c[1<<24],d[1<<24];
int us[1111],lg[1<<24],pc[1<<24];
void fwt(unt*v,int V)
{
	register int i,ii,iii;
	for(i=1;i<V;i<<=1)
		for(ii=0;ii<V;ii+=(i<<1))
			for(iii=0;iii<i;iii++)v[i+ii+iii]+=v[ii+iii];
}
int S;
unt calc()
{
	unt ret=0;
	for(register int i=0;i<=S;i++)ret+=((pc[S^i])&1)?-d[i]:d[i];
	return ret;
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(i=1;i<=n;i++)
		for(ii=i+1;ii<=n;ii++)
			if(mp[i][ii]=='A')merge(i,ii);
	for(i=1;i<=n;i++)
		for(ii=i+1;ii<=n;ii++)
			if(mp[i][ii]=='X')if(rt(i)==rt(ii))return puts("-1"),0;
	int Idx=0;
	for(i=1;i<=n;i++)if(!fa[i])if(vs[i])vs[i]=++Idx;
	if(!Idx)return printf("%d\n",n-1),0;
	S=(1<<Idx)-1;
	for(i=1;i<=n;i++)
		for(ii=i+1;ii<=n;ii++)
			if(mp[i][ii]=='X')
			{
				int A=vs[rt(i)],B=vs[rt(ii)];
				if(A&&B)us[A]|=(1<<(B-1)),us[B]|=(1<<(A-1));
			}
	for(i=0;i<=Idx;i++)lg[1<<i]=i+1;
	for(i=1;i<=n;i++)us[i]^=S;
	for(i=1;i<=S;i++)pc[i]=pc[i>>1]+(i&1);
	for(i=c[0]=1;i<=S;i++)
	{
		int G=i&-i,T=i^G;
		c[i]=c[T]&&((us[lg[G]]&T)==T);
	}
	int tot=n;
	if(c[S])return printf("%d\n",n),0;
	fwt(c,S+1);
	for(i=0;i<=S;i++)d[i]=c[i]*c[i];
	while(1)
	{
		tot++;
		if(calc())return printf("%d\n",tot),0;
		for(i=0;i<=S;i++)d[i]=d[i]*c[i];
	}
}
/*
Please don't let me down.
*/