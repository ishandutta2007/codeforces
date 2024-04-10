#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ans=0;
int a[1002][1002],b[1002][1002];
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
		read(n),memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				read(a[i][j]);
		for(int i=1;i<=n;++i)b[1][i]=0;
		for(int i=2;i<=n;++i)
			for(int j=1;j<=n;++j)
				b[i][j]=(a[i-1][j]^b[i-1][j-1]^b[i-1][j+1]^b[i-2][j]),ans^=b[i][j];
		printf("%d\n",ans);
	}
	return 0;
}