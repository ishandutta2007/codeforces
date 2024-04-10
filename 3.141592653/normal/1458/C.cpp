#include<bits/stdc++.h>
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
using std::sort;
using std::min;
using std::max;
using std::swap;
using std::reverse;
struct pii{int x,y;};
bool operator<(const pii x,const pii y){return x.x^y.x?x.x<y.x:x.y<y.y;}
ll gcd(ll x,ll y){for(ll r=y;r;r=x%y,x=y,y=r);return x;}
int n,m;
int a[1111][1111],b[1111][1111],p[1111],q[1111];
char str[1111111];
void I()
{
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		for(ii=1;ii<=n;ii++)p[ii]=a[i][ii];
		for(ii=1;ii<=n;ii++)q[p[ii]]=ii;
		for(ii=1;ii<=n;ii++)
			a[i][ii]=q[ii];
	}
}
void C()
{
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		for(ii=1;ii<=n;ii++)
			p[ii]=a[ii][i];
		for(ii=1;ii<=n;ii++)q[p[ii]]=ii;
		for(ii=1;ii<=n;ii++)
			a[ii][i]=q[ii];
	}
}
void X()
{
	register int i,ii;
	for(i=1;i<=n;i++)for(ii=i+1;ii<=n;ii++)swap(a[i][ii],a[ii][i]);
}
void A(int x)
{
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)b[i][(ii+x-1)%n+1]=a[i][ii];
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)a[i][ii]=b[i][ii];
}
void B(int y)
{
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)b[(i+y-1)%n+1][ii]=a[i][ii];
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)a[i][ii]=b[i][ii];
}
void V(int v)
{
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)a[i][ii]=(a[i][ii]+v-1)%n+1;
}
void exec()
{
	scanf("%d%d",&n,&m);
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)scanf("%d",a[i]+ii);
	int cx=0,cy=0,cv=0,Px=0,Pi=0,Pc=0;
	scanf("%s",str+1);
	for(i=1;i<=m;i++)
	{
		if(str[i]=='I')
		{
			if(Pi){Pi=0;continue;}
			if(Pc){Px=!Px;continue;}
			Pi=1;
		}if(str[i]=='C')
		{
			if(Pc){Pc=0;continue;}
			if(Pi){Px=!Px;continue;}
			Pc=1;
		}
		if(Pi)
		{
			if(str[i]=='L'){cv--;continue;}
			if(str[i]=='R'){cv++;continue;}
		}
		if(Pc)
		{
			if(str[i]=='U'){cv--;continue;}
			if(str[i]=='D'){cv++;continue;}
		}
		if(Px)
		{
			if(str[i]=='L')str[i]='U';
			else if(str[i]=='U')str[i]='L';
			if(str[i]=='R')str[i]='D';
			else if(str[i]=='D')str[i]='R';
		}if(str[i]=='L')cx--;
		if(str[i]=='R')cx++;
		if(str[i]=='U')cy--;
		if(str[i]=='D')cy++;
	}//printf(">>%d %d %d\n",cx,cy,cv);
	cx=cx%n+n,cy=cy%n+n,cv=cv%n+n;
	//printf("%d %d %d %d %d %d\n",cx%n,cy%n,cv%n,Px,Pi,Pc);
	A(cx),B(cy),V(cv);
	if(Px)X();
	if(Pi)I();
	if(Pc)C();
	for(i=1;i<=n;i++,puts(""))
		for(ii=1;ii<=n;ii++)printf("%d ",a[i][ii]);
	puts("");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}