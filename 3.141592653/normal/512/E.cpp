#include<cstdio>
#include<algorithm>
int n;
struct movauto
{
	int x[1111],y[1111],a[1111],b[1111];
	int Id[1111][1111];
	bool close(int x,int y)
	{return Id[x][y]||(x==y%n+1)||(y==x%n+1);}
	void init()
	{
		register int i,ii;
		for(i=1;i<=n-3;i++)
			for(ii=1;ii<=n;ii++)
				if(close(x[i],ii)&&close(y[i],ii))
				{
					if(!a[i])a[i]=ii;
					else b[i]=ii;
				}
	}
	struct logItem
	{int a,b,c,d;}log[111111];
	int lc;
	void enlog(int a,int b,int c,int d)
	{log[++lc]=(logItem){a,b,c,d};}
	void replace(int i,int x,int y)
	{
		if(a[i]==x)a[i]=y;
		if(b[i]==x)b[i]=y;
	}
	void flip(int i)
	{
		enlog(x[i],y[i],a[i],b[i]);
		Id[a[i]][b[i]]=Id[b[i]][a[i]]=i;
		int A=Id[a[i]][x[i]],B=Id[a[i]][y[i]],
		C=Id[b[i]][x[i]],D=Id[b[i]][y[i]];
		replace(A,y[i],b[i]),replace(C,y[i],a[i]),
		replace(B,x[i],b[i]),replace(D,x[i],a[i]);
		std::swap(x[i],a[i]),std::swap(y[i],b[i]);
	}
	void rd()
	{
		register int i;
		for(i=1;i<=n-3;i++)
			scanf("%d%d",x+i,y+i),
			Id[x[i]][y[i]]=Id[y[i]][x[i]]=i;
		init();
	}
	void sol()
	{
		while(1)
		{
			for(register int i=1;i<=n-3;i++)
				if(a[i]==1||b[i]==1){flip(i);goto C;}
			break;C:;
		}
	}
}A,B;
void prt()
{
	register int i;
	printf("%d\n",A.lc+B.lc);
	for(i=1;i<=A.lc;i++)
		printf("%d %d\n",A.log[i].a,A.log[i].b);
	for(i=B.lc;i;i--)
		printf("%d %d\n",B.log[i].c,B.log[i].d);
}
int main()
{scanf("%d",&n),A.rd(),B.rd(),A.sol(),B.sol(),prt();}
/*
Please don't let me down.
*/