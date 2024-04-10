#include<cstdio>
using namespace std;
#define N 105
int n,m,a,b,c,fg,tp[N],sa[N],sb[N],st=1,t1[N],ls[N],ty[N],l2[N],f2,r2[N];
char as[N*2][N*2];
void doit()
{
	int vl=(c-m)/m/2*2+1;
	for(int i=1;i<=m;i++)tp[i]=vl,c-=vl;
	for(int i=1;i<=m&&c;i++,st=i)tp[i]+=2,c-=2;
	int f1=a/m;
	for(int i=1;i<=m;i++)sa[i]=f1,a-=f1;
	for(int i=m;i>=st&&a;i--)sa[i]++,a--;
	for(int i=m;i>=st&&a;i--)sa[i]++,a--;
	for(int i=m;i>=1&&a;i--)sa[i]++,a--;
	for(int i=1;i<=m;i++)sb[i]=n-sa[i]-tp[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(sb[j]>=i)t1[j]=2;else if(sb[j]+tp[j]>=i)t1[j]=3;else t1[j]=1;
		int rb=0,fg=1;
		for(int j=m;j>=1;j--)
		{
			if(t1[j]==1){if(rb==0){fg=0;break;}l2[j]=1;}
			if(t1[j]==2){if(rb==1){fg=0;break;}l2[j]=0;}
			if(t1[j]==3){ty[j]=ls[j]<<1|rb;rb^=1;l2[j]=!ls[j];}
		}
		rb=r2[i]=!fg;
		for(int j=m;j>=1;j--)
		{
			if(t1[j]==1){if(rb==0){fg=0;break;}l2[j]=1;}
			if(t1[j]==2){if(rb==1){fg=0;break;}l2[j]=0;}
			if(t1[j]==3){ty[j]=ls[j]<<1|rb;rb^=1;l2[j]=!ls[j];}
		}
		for(int j=m;j>=1;j--)
		{
			if(t1[j]==1)as[i*2-1][j*2-1]=as[i*2-1][j*2]=as[i*2][j*2-1]=as[i*2][j*2]='#';
			if(t1[j]==2)as[i*2-1][j*2-1]=as[i*2-1][j*2]=as[i*2][j*2-1]=as[i*2][j*2]='.';
			if(t1[j]==3)
			{
				if(ty[j]==0)as[i*2-1][j*2-1]='\\',as[i*2-1][j*2]='.',as[i*2][j*2-1]='#',as[i*2][j*2]='\\';
				if(ty[j]==1)as[i*2-1][j*2-1]='.',as[i*2-1][j*2]='/',as[i*2][j*2-1]='/',as[i*2][j*2]='#';
				if(ty[j]==3)as[i*2-1][j*2-1]='\\',as[i*2-1][j*2]='#',as[i*2][j*2-1]='.',as[i*2][j*2]='\\';
				if(ty[j]==2)as[i*2-1][j*2-1]='#',as[i*2-1][j*2]='/',as[i*2][j*2-1]='/',as[i*2][j*2]='.';
			}
			ls[j]=l2[j];
		}
	}
	if(fg)if(as[1][m*2]=='.'&&as[2][m*2-1]=='.')as[1][m*2-1]=as[2][m*2]='\\',as[1][m*2]='#',r2[1]=1;
	else as[1][2]=as[2][1]='/',as[1][1]='#';
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	if((c^m)&1)c--,b++,fg++;
	while(a+b<m)c-=n,m--,f2++;
	if(m)doit();
	for(int i=1;i<=f2;i++)
	{
		m++;
		int r=0;
		for(int j=1;j<=n;j++)ty[j]=r2[j]|r<<1,r2[j]^=1,r^=1;
		for(int j=1;j<=n;j++)
		{
				if(ty[j]==1)as[j*2-1][m*2-1]='\\',as[j*2-1][m*2]='.',as[j*2][m*2-1]='#',as[j*2][m*2]='\\';
				if(ty[j]==0)as[j*2-1][m*2-1]='.',as[j*2-1][m*2]='/',as[j*2][m*2-1]='/',as[j*2][m*2]='#';
				if(ty[j]==2)as[j*2-1][m*2-1]='\\',as[j*2-1][m*2]='#',as[j*2][m*2-1]='.',as[j*2][m*2]='\\';
				if(ty[j]==3)as[j*2-1][m*2-1]='#',as[j*2-1][m*2]='/',as[j*2][m*2-1]='/',as[j*2][m*2]='.';
		}
	}
	for(int i=1;i<=n*2;i++)printf("%s\n",as[i]+1);
}