#include<cstdio>
#define LL long long
int Test_num;LL a,b,c,k,mn,mx;
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
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(a),read(k);
		while(--k)
		{
			b=a,mn=9,mx=0;
			while(b)c=b%10,b/=10,mn=min(mn,c),mx=max(mx,c);
			if(!mn)break;
			a+=mn*mx;
		}
		printf("%lld\n",a);
	}
	return 0;
}