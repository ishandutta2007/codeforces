#include<bits/stdc++.h>
using namespace std;
int Test_num,n,m,a,b;
char c[1002][1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve()
{
	if(m&1)
	{
		puts("YES");
		for(int k=0;k<=m;++k)
			printf("%d%c",(k&1)? 1:2,k==m? '\n':' ');
		return ;
	}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(c[i][j]==c[j][i])
			{
				puts("YES");
				for(int k=0;k<=m;++k)
					printf("%d%c",(k&1)? i:j,k==m? '\n':' ');
				return ;
			}
	for(int i=1;i<=n;++i)
	{
		a=b=0;
		for(int j=1;j<=n;++j)
			if(j!=i)
			{
				if(c[i][j]=='a')a=j;
				if(c[i][j]=='b')b=j;
			}
		if(a && b)
		{
			puts("YES");
			if((m/2)&1)
			{
				for(int j=m/2;~j;--j)printf("%d ",(j&1)? a:i);
				for(int j=m/2;j;--j)printf("%d%c",(j&1)? b:i,j==1? '\n':' ');
			}
			else
			{
				for(int j=m/2;~j;--j)printf("%d ",(j&1)? a:i);
				for(int j=m/2;j;--j)printf("%d ",(j&1)? i:b,j==1? '\n':' ');
			}
			return ;
		}
	}
	puts("NO");
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=1;i<=n;++i)scanf("%s",c[i]+1);
		solve();
	}
	return 0;
}