#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,Test_num,X,pos;
bool ok;
int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline bool check()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			if(a[num(i,j)]>a[num(i,j+1)])
				return 0;
	return 1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				read(a[num(i,j)]);
		if(check())
		{
			puts("1 1");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			ok=1;
			for(int j=1;j<m;++j)
				if(a[num(i,j)]>a[num(i,j+1)])
				{
					ok=0;
					//j and zhi hou di yi ge xiao deng yu a[num(i,j+1)] de huan
					pos=-1;
					for(int k=1;k<=j;++k)
					{
						//printf("j+1:%d k:%d\n",j+1,k);
						if((k==1 || a[num(i,j+1)]>=a[num(i,k-1)]) && (j+1==m || a[num(i,k)]<=a[num(i,j+2)])
						&& (k+1==j+1 || (a[num(i,j+1)]<=a[num(i,k+1)] && a[num(i,k)]>=a[num(i,j)])))
						{
							X=j+1,pos=k;
							break;
						}
					}
					if(!(~pos))for(int k=j+1;k<=m;++k)
						if((k==m || a[num(i,j)]<=a[num(i,k+1)]) && (j==1 || a[num(i,k)]>=a[num(i,j-1)])
						&& (k+1==j || (a[num(i,j)]>=a[num(i,k-1)] && a[num(i,k)]<=a[num(i,j+1)])))
						{
							X=j,pos=k;
							break;
						}
					//printf(" j:%d pos:%d\n",j,pos);
					if(!(~pos))
					{
						puts("-1");
						goto QAQ;
					}
					/*for(int i=1;i<=n;++i)
						for(int j=1;j<=m;++j)
							printf("%2d%c",a[num(i,j)],j==m? '\n':' ');*/
					for(int k=1;k<=n;++k)swap(a[num(k,X)],a[num(k,pos)]);
					/*for(int i=1;i<=n;++i)
						for(int j=1;j<=m;++j)
							printf("%2d%c",a[num(i,j)],j==m? '\n':' ');*/
					break;
				}
			if(ok)continue;
			break;
		}
		//printf("ee %d %d\n",X,pos);
		if(!check())puts("-1");
		else printf("%d %d\n",X,pos);
		QAQ:;
	}
	return 0;
}