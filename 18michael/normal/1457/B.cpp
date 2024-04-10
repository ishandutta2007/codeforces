#include<cstdio>
int n,k,res,ans,Test_num;
int c[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k),ans=n;
		for(int i=1;i<=n;++i)read(c[i]);
		for(int i=1;i<=100;++i)
		{
			res=0;
			for(int j=1;j<=n;)
			{
				if(c[j]!=i)j+=k,++res;
				else ++j;
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}