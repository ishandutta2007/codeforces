#include<cstdio>
int n,p,k,x,y,Test_num,ans;
char c;
int a[100002],la[100002];
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
		read(n),read(p),read(k);
		for(int i=1;i<=n;++i)
		{
			do c=getchar();while(c!='0' && c!='1');
			la[i]=a[i]=(c=='0');
		}
		for(int i=n-k;i>0;--i)la[i]+=la[i+k];
		read(x),read(y),ans=n*x;
		for(int i=p;i<=n;++i)ans=min(ans,la[i]*x+(i-p)*y);
		printf("%d\n",ans);
	}
	return 0;
}