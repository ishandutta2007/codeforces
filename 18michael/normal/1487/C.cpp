#include<cstdio>
int n,n1,Test_num;
int ok[102][102];
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
		read(n),n1=n-((n&1)^1);
		for(int i=1;i<=n1/2;++i)
			for(int j=1;j<=n;++j)
				ok[j][((i+j-1)%n)+1]=1;
		for(int i=n/2+1;i<n;++i)
			for(int j=1;j<=n;++j)
				ok[j][((i+j-1)%n)+1]=-1;
		if(!(n&1))for(int i=1;i<=n;++i)ok[i][((i+(n/2)-1)%n)+1]=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				printf("%d ",ok[i][j]);
		puts("");
	}
	return 0;
}