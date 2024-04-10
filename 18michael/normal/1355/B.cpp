#include<cstdio>
#include<algorithm>
using namespace std;
int n,la,t,ans,Test_num;
int a[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		t=ans=0,read(n);
		for(int i=1;i<=n;++i)
			read(a[i]);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;)
		{
			la=a[i],++t,++i;
			while(i<=n)
			{
				if(a[i]==la)++t,++i;
				else break;
			}
			ans+=t/la,t%=la;
		}
		printf("%d\n",ans);
	}
	return 0;
}