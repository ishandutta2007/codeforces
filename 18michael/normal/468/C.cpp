#include<cstdio>
#define LL __int128
#define Mx 999999999999999999
LL a,res,res1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
template<class T>void write(T x)
{
	if(x>9)write(x/10);
	putchar((x%10)^48);
}
inline LL calc(LL x)
{
	res1=0;
	for(int i=1;i<=9;++i)
	{
		res=0;
		for(LL j=10;j/10<=x;j*=10)
		{
			if(j/10*(i+1)<=x)res=(res+((x-j/10*(i+1))/j+1)*(j/10))%a;
			res=(res+((x/(j/10))%10==i? ((x%(j/10))+1):0))%a;
		}
		res1=(res1+res*i)%a;
	}
	return res1;
}
int main()
{
	read(a),res=(a-(calc(Mx)%a)-1)%a+1,write(res),putchar(' '),write(res+Mx);
	return 0;
}