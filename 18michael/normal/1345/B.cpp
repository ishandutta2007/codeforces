#include<cstdio>
int n,res,ans,Test_num;
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
		while(res=2)
		{
			if(n<res)break;
			while(n>=res)n-=res,res+=3;
			++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}