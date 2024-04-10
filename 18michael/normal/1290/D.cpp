#include<bits/stdc++.h>
using namespace std;
int N,K,ans;
char ch;
bool vis[1032];
inline bool Order(int x)
{
	printf("? %d\n",x),fflush(stdout);
	do ch=getchar();while(ch!='Y' && ch!='N');
	return (ch=='Y');
}
inline void Change()
{
	puts("R"),fflush(stdout);
}
inline void Print()
{
	printf("! %d\n",ans),fflush(stdout);
}
int main()
{
	scanf("%d%d",&N,&K),ans=N;
	if(K==1)
	{
		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<i;++j)
			{
				Order(j);
				if(Order(i))
				{
					--ans;
					break;
				}
			}
			Change();
		}
		Print();
		return 0;
	}
	for(int i=1;i<=N/K;++i)
	{
		for(int j=1,x;j<=N/K;++j)
		{
			x=(i-j+1+2*N/K)%(2*N/K);
			for(int l=1;l<=K/2;++l)
				if(!vis[x*K/2+l] && Order(x*K/2+l))
					vis[x*K/2+l]=1,--ans;
			x=(i+j+2*N/K)%(2*N/K);
			for(int l=1;l<=K/2;++l)
				if(!vis[x*K/2+l] && Order(x*K/2+l))
					vis[x*K/2+l]=1,--ans;
		}
		Change();
	}
	Print();
	return 0;
}