#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,m,k;
int col[1111];
int To[1111][1111],Tr[1111][1111],rev[1111],deg[1111],dep;
void adjust(int y,int A,int B)
{
	col[Tr[y][A]]=B;
	int TP=To[y][A];To[y][A]=To[y][B],To[y][B]=TP,
	TP=Tr[y][A],Tr[y][A]=Tr[y][B],Tr[y][B]=TP;
	if(To[y][B])adjust(To[y][B],B,A);
}
void ins(int x,int y,int t)
{
	if(deg[x]%k==0)rev[x]=++dep;
	if(deg[y]%k==0)rev[y]=++dep;
	deg[x]++,deg[y]++,x=rev[x],y=rev[y];
	register int i;
	int A=0,B=0;
	for(i=1;i<=k;i++)
		if(!(To[x][i]|To[y][i]))
			{col[t]=i,To[x][i]=y,Tr[x][i]=t,To[y][i]=x,Tr[y][i]=t;return;}
	for(i=1;i<=k;i++)if(!To[x][i])A=i;
	for(i=1;i<=k;i++)if(!To[y][i])B=i;
	adjust(y,A,B),col[t]=A,To[x][A]=y,Tr[x][A]=t,To[y][A]=x,Tr[y][A]=t;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	register int i;
	for(i=1;i<=n;i++)scanf("%*d");
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),ins(x,y+n,i);
	}for(i=1;i<=m;i++)printf("%d\n",col[i]);
}
/*
Just go for it.
*/