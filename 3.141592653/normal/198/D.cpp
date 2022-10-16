#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,a[111][111][111];
int X=2,Y=1,Z=1,Lx=50,Rx=51,Ly=50,Ry=50,Lz=50,Rz=50,L=1e8,R=L+2;
int Sx=50,Sy=50,Sz=50,Tx=51,Ty=50,Tz=50;
void print()
{
	register int i,ii,iii;
	for(i=Lx;i<=Rx;i++,puts(""))
		for(ii=Ly;ii<=Ry;ii++,puts(""))
			for(iii=Lz;iii<=Rz;iii++)
				printf("%d ",a[i][ii][iii]-L);
}
void recs(){a[Sx][Sy][Sz]=L--;}
void rect(){a[Tx][Ty][Tz]=++R;}
void XZS()
{
	Y++;
	register int i;
	if(Sy==Ry)Sy++,Ry++;else Sy--,Ly--;recs();
	int Vx=Lx+Rx-Sx,Vz=Sz,dx=(Lx==Sx)?1:-1,dz=(Lz==Sz)?1:-1;
	int le=X;
	while(1)
	{
		if(Vx==Sx&&Vz==Sz)break;
		for(i=1;i<le;i++)Sz+=dz,recs();
		for(i=1;i<le;i++)Sx+=dx,recs();
		Sz-=dz,recs();
		if(Vx==Sx&&Vz==Sz)break;
		le--,dx=-dx,dz=-dz;
		for(i=1;i<le;i++)Sx+=dx,recs();
		for(i=1;i<le;i++)Sz+=dz,recs();
		Sx-=dx,recs();
		le--,dx=-dx,dz=-dz;
	}
}
void XZT()
{
	Y++;
	register int i;
	if(Ty==Ry)Ty++,Ry++;else Ty--,Ly--;rect();
	int Vx=Lx+Rx-Tx,Vz=Tz,dx=(Lx==Tx)?1:-1,dz=(Lz==Tz)?1:-1;
	int le=X;
	while(1)
	{
		if(Vx==Tx&&Vz==Tz)break;
		for(i=1;i<le;i++)Tz+=dz,rect();
		for(i=1;i<le;i++)Tx+=dx,rect();
		Tz-=dz,rect();
		if(Vx==Tx&&Vz==Tz)break;
		le--,dx=-dx,dz=-dz;
		for(i=1;i<le;i++)Tx+=dx,rect();
		for(i=1;i<le;i++)Tz+=dz,rect();
		Tx-=dx,rect();
		le--,dx=-dx,dz=-dz;
	}
}
void YZS()
{
	X++;
	register int i;
	if(Sx==Rx)Sx++,Rx++;else Sx--,Lx--;recs();
	int Vy=Ly+Ry-Sy,Vz=Sz,dy=(Ly==Sy)?1:-1,dz=(Lz==Sz)?1:-1;
	int le=Y;
	while(1)
	{
		if(Vy==Sy&&Vz==Sz)break;
		for(i=1;i<le;i++)Sz+=dz,recs();
		for(i=1;i<le;i++)Sy+=dy,recs();
		Sz-=dz,recs();
		if(Vy==Sy&&Vz==Sz)break;
		le--,dy=-dy,dz=-dz;
		for(i=1;i<le;i++)Sy+=dy,recs();
		for(i=1;i<le;i++)Sz+=dz,recs();
		Sy-=dy,recs();
		le--,dy=-dy,dz=-dz;
	}
}
void YZT()
{
	X++;
	register int i;
	if(Tx==Rx)Tx++,Rx++;else Tx--,Lx--;rect();
	int Vy=Ly+Ry-Ty,Vz=Tz,dy=(Ly==Ty)?1:-1,dz=(Lz==Tz)?1:-1;
	int le=Y;
	while(1)
	{
		if(Vy==Ty&&Vz==Tz)break;
		for(i=1;i<le;i++)Tz+=dz,rect();
		for(i=1;i<le;i++)Ty+=dy,rect();
		Tz-=dz,rect();
		if(Vy==Ty&&Vz==Tz)break;
		le--,dy=-dy,dz=-dz;
		for(i=1;i<le;i++)Ty+=dy,rect();
		for(i=1;i<le;i++)Tz+=dz,rect();
		Ty-=dy,rect();
		le--,dy=-dy,dz=-dz;
	}
}
void XYT()
{
	Z++,Rz++,Tz++,rect();
	int Vx=Lx+Rx-Tx,Vy=Ly+Ry-Ty;
	while(1)
	{
		if(Tx==Vx&&Ty==Vy)break;
		if(Tx-1>=Lx&&!a[Tx-1][Ty][Tz])Tx--;
		else if(Tx+1<=Rx&&!a[Tx+1][Ty][Tz])Tx++;
		else if(Ty-1>=Ly&&!a[Tx][Ty-1][Tz])Ty--;
		else Ty++;
		rect();
	}
}
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("1"),0;
	register int i;
	a[Lx][Ly][Lz]=1e8+1,a[Rx][Ly][Lz]=1e8+2;
	for(i=2;;i++)
	{
		if(X==Z&&Z==Y+1)
		{
			XZS();
			if(Y==n)return print(),0;
			XZT();
		}
		else if(Y==Z&&Z==X+1)
		{
			YZS();
			if(X==n)return print(),0;
			YZT();
		}else XYT();
	}
}
/*
Please don't let me down.
*/