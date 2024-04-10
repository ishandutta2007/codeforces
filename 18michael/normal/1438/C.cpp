#include<cstdio>
int n,m,Test_num;
int v[102][102];
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
		read(n),read(m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				read(v[i][j]),v[i][j]+=((v[i][j]^i^j)&1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				printf("%d%c",v[i][j],j==m? '\n':' ');
	}
	return 0;
}