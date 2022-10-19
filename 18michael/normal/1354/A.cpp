#include<cstdio>
#define LL long long
int Test_num;LL a,b,c,d,ans;
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
		read(a),read(b),read(c),read(d),ans=b,a-=b;
		if(a>0)
		{
			if(c<=d)ans=-1;
			else
			{
				if(!(a%(c-d)))ans+=a/(c-d)*c;
				else ans+=(a/(c-d)+1)*c;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}