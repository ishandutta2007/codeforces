#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num;
LL k,pw[62];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve(int x,LL y)
{
	if(x>n)return ;
	for(int i=n-x;~i;--i)
	{
		if(i && i<=60 && pw[i-1]<y){y-=pw[i-1];continue;}
		for(int j=x+(n-x-i);j>=x;--j)printf("%d ",j);
		solve(x+(n-x-i)+1,y);return ;
	}
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=60;++i)pw[i]=(pw[i-1]<<1);
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k);
		if(n<=60 && pw[n-1]<k)
		{
			puts("-1");
			continue;
		}
		solve(1,k),puts("");
	}
	return 0;
}