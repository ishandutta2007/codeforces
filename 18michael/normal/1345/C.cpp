#include<cstdio>
int n,x,ans,Test_num;
bool u[200002];
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
		ans=0,read(n);
		for(int i=0;i<n;++i)
			u[i]=0;
		for(int i=1;i<=n;++i)
		{
			read(x),x=(i+x)%n,x=(x+n)%n;
			if(u[x])ans=1;
			else u[x]=1;
		}
		if(ans)puts("NO");
		else puts("YES");
	}
	return 0;
}