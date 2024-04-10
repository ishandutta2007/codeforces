#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
int cnt[11][11];
int ex[1111111],ey[1111111],eg;
int fa[1111111];
int rt(int x)
{return fa[x]?fa[x]=rt(fa[x]):x;}
void pushb(int x,int y)
{ex[++eg]=x,ey[eg]=y,fa[rt(x)]=rt(y);}
#include<cstdlib>
void shut()
{puts("-1"),exit(0);}
int lg[1111111];
int stk[11][1111111],top[11];
int rem[11][11];
void print()
{
	register int i;
	for(i=1;i<n;i++)
	{
		if(!rem[lg[ex[i]]][lg[ey[i]]])
			ex[i]^=ey[i]^=ex[i]^=ey[i];
		printf("%d %d\n",ex[i],ey[i]);
	}
}
int it[1111];
void insert(int x,int y)
{
	while(1)
	{
		it[x]%=top[x],it[y]%=top[y];
		it[x]++,it[y]++;
		int xx=stk[x][it[x]],yy=stk[y][it[y]];
		if(rt(xx)==rt(yy))it[x]++;
		else{pushb(xx,yy);break;}
	}
}
void solve()
{
	register int i,ii;
	for(i=1;i<=6;i++)it[i]=0;
	for(i=1;i<=6;i++)
		for(ii=1;ii<i;ii++)
			while(cnt[i][ii]--)insert(i,ii);
}
int deg[11];
int popcnt[111];
int edg(int S)
{
	register int i,ii;
	int ret=0;
	for(i=1;i<=6;i++)
		if(S&(1<<(i-1)))
			for(ii=1;ii<i;ii++)
				if(S&(1<<(ii-1)))
					ret+=cnt[i][ii];
	return ret;
}
int ver(int S)
{
	register int i;
	int ret=0;
	for(i=1;i<=6;i++)if(S&(1<<(i-1)))ret+=top[i];
	return ret;
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<n;i++)
	{
		char s[11],ss[11];
		scanf("%s%s",s,ss);
		int x=strlen(s),y=strlen(ss);
		rem[x][y]++;
		if(x<y)x^=y^=x^=y;
		cnt[x][y]++;
	}for(i=1;i<=n;i++)lg[i]=lg[i/10]+1;
	for(i=1;i<=n;i++)stk[lg[i]][++top[lg[i]]]=i;
	for(i=1;i<=6;i++)
		while(cnt[i][i])
		{
			if(top[i]<2)shut();
			pushb(stk[i][top[i]],stk[i][top[i]-1]),top[i]--,cnt[i][i]--;
		}
	if(eg==n-1)return print(),0;
	for(i=1;i<(1<<6);i++)popcnt[i]=popcnt[i>>1]+(i&1);
	for(i=1;i<(1<<6);i++)
		if(popcnt[i]>1)
			if(ver(i)&&edg(i)>=ver(i))shut();
	solve(),print();
}
/*
Just go for it.
*/