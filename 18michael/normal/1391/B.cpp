#include<cstdio>
int Test_num,n,m,ans;
char ch;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				do ch=getchar();while(ch!='R' && ch!='D' && ch!='C');
				ans+=((i==n && ch=='D') || (j==m && ch=='R'));
			}
		printf("%d\n",ans);
	}
	return 0;
}