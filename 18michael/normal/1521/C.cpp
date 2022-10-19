#include<bits/stdc++.h>
using namespace std;
int Test_num,n,mx,t;
int p[10002];
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
		read(n);
		for(int i=1;i<=n;i+=2)
		{
			i-=(i==n),printf("? 1 %d %d %d\n",i,i+1,n-1),fflush(stdout),scanf("%d",&mx);
			if(mx==n-1)printf("? 1 %d %d %d\n",i+1,i,n-1),fflush(stdout),scanf("%d",&mx);
			printf("? 1 %d %d %d\n",i,i+1,mx-1),fflush(stdout),scanf("%d",&t);
			if(t==mx)p[i+1]=mx,printf("? 2 %d %d %d\n",i,i+1,1),fflush(stdout),scanf("%d",&p[i]);
			else p[i]=mx,printf("? 2 %d %d %d\n",i+1,i,1),fflush(stdout),scanf("%d",&p[i+1]);
		}
		printf("! ");for(int i=1;i<=n;++i)printf("%d%c",p[i],i==n? '\n':' ');fflush(stdout);
	}
	return 0;
}