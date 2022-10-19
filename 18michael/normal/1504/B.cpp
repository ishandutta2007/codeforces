#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ok;
int c[300002],d[300002];
char a[300002],b[300002];
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
		read(n),scanf("%s%s",a+1,b+1),ok=1;
		for(int i=1;i<=n;++i)c[i]=(c[i-1]+((a[i]^48)? 1:-1)),d[i]=(a[i]^b[i]);
		d[n+1]=0;
		for(int i=n;i;--i)
			if(((d[i+1]^d[i])&1) && c[i])
			{
				ok=0;
				break;
			}
		puts(ok? "YES":"NO");
	}
	return 0;
}