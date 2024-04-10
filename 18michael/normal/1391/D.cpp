#include<cstdio>
int Test_num,n,m,t;
char ch;
int f[1000002][8];
bool a[1000002][4];
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
int main()
{
	read(n),read(m);if(n>m)t=n,n=m,m=t;
	if(n>=4)return 0&puts("-1");
	if(n==1)return 0&puts("0");
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			do ch=getchar();while(ch!='0' && ch!='1');
			a[j][i]=(ch^48);
		}
	if(n==2)
	{
		f[1][1]=1-(f[1][0]=(a[1][1]^a[1][2]));
		for(int i=2;i<=m;++i)f[i][0]=f[i-1][1]+(a[i][1]^a[i][2]),f[i][1]=f[i-1][0]+1-(a[i][1]^a[i][2]);
		return 0&printf("%d",min(f[m][0],f[m][1]));
	}
	f[1][0]=3-a[1][1]-a[1][2]-a[1][3];
	f[1][1]=2+a[1][1]-a[1][2]-a[1][3];
	f[1][2]=2-a[1][1]+a[1][2]-a[1][3];
	f[1][3]=1+a[1][1]+a[1][2]-a[1][3];
	f[1][4]=2-a[1][1]-a[1][2]+a[1][3];
	f[1][5]=1+a[1][1]-a[1][2]+a[1][3];
	f[1][6]=1-a[1][1]+a[1][2]+a[1][3];
	f[1][7]=a[1][1]+a[1][2]+a[1][3];
	for(int i=2;i<=m;++i)
	{
		f[i][0]=min(f[i-1][2],f[i-1][5])+3-a[i][1]-a[i][2]-a[i][3];
		f[i][1]=min(f[i-1][3],f[i-1][4])+2+a[i][1]-a[i][2]-a[i][3];
		f[i][2]=min(f[i-1][0],f[i-1][7])+2-a[i][1]+a[i][2]-a[i][3];
		f[i][3]=min(f[i-1][1],f[i-1][6])+1+a[i][1]+a[i][2]-a[i][3];
		f[i][4]=min(f[i-1][1],f[i-1][6])+2-a[i][1]-a[i][2]+a[i][3];
		f[i][5]=min(f[i-1][0],f[i-1][7])+1+a[i][1]-a[i][2]+a[i][3];
		f[i][6]=min(f[i-1][3],f[i-1][4])+1-a[i][1]+a[i][2]+a[i][3];
		f[i][7]=min(f[i-1][2],f[i-1][5])+a[i][1]+a[i][2]+a[i][3];
	}
	return 0&printf("%d",min(min(min(f[m][0],f[m][1]),min(f[m][2],f[m][3])),min(min(f[m][4],f[m][5]),min(f[m][6],f[m][7]))));
}