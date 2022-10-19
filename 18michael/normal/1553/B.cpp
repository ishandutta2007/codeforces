#include<bits/stdc++.h>
using namespace std;
int n,ls,lt,ok,Test_num;
char s[502],t[1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int check(int x,int y)
{
	for(int i=x;i<=y;++i)
		if(s[i]!=t[i-x+1])
			return 0;
	for(int i=y-1;i>=(2*y-x+1)-lt;--i)
		if(s[i]!=t[2*y-x+1-i])
			return 0;
	return 1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		scanf("%s%s",s+1,t+1),ls=strlen(s+1),lt=strlen(t+1),ok=0;
		for(int i=1;i<=ls;++i)
			for(int j=i;j<=ls && i+lt-1>=j;++j)
				if(check(i,j))
				{
					ok=1;
					break;
				}
		puts(ok? "YES":"NO");
	}
	return 0;
}