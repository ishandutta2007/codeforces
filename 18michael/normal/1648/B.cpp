#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,c,Test_num;bool ok;
int a[1000002],pre[2000002];
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
		read(n),read(c),ok=1;
		for(int i=1;i<=2*c;++i)pre[i]=0;
		for(int i=1,x;i<=n;++i)read(x),++pre[x];
		for(int i=1;i<=2*c;++i)pre[i]+=pre[i-1];
		for(int i=1;i<=c;++i)
			if(pre[i]-pre[i-1])
				for(int j=1;j<=c/i;++j)
					if(!(pre[j]-pre[j-1]) && (pre[i*j+i-1]-pre[i*j-1]))
					{
						ok=0;
						break;
					}
		puts(ok? "Yes":"No");
	}
	return 0;
}