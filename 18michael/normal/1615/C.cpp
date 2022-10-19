#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,A,B,C,D,t0,t1,ans,Test_num;
char a[100002],b[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int A,int B,int C,int D,int o,int t)
{
	if(A==t1 && !B && !C && D==t0)
	{
		ans=min(ans,t);
		return ;
	}
	if((o&1) && A)dfs(C+1,D,A-1,B,2,t+1);
	if((o&2) && B)dfs(C,D+1,A,B-1,1,t+1);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),scanf("%s%s",a,b),A=B=C=D=t0=t1=0,ans=inf;
		for(int i=0;i<n;++i)
		{
			if(a[i]=='1')
			{
				if(b[i]=='1')++A;
				else ++B;
			}
			else
			{
				if(b[i]=='1')++C;
				else ++D;
			}
			t0+=(b[i]=='0'),t1+=(b[i]=='1');
		}
		dfs(A,B,C,D,3,0),printf("%d\n",ans==inf? -1:ans);
	}
	return 0;
}