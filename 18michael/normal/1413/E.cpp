#include<bits/stdc++.h>
#define LL long long
using namespace std;
int Test_num;
LL a,b,c,d,e;
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
		read(a),read(b),read(c),read(d);
		if(a>b*c)puts("-1");
		else if(d*b-a>=0)printf("%lld\n",a);
		else
		{
			e=(2*a-d*b)/2/d/b;
			if(e<0)printf("%lld\n",a);
			else if(e>=c/d)printf("%lld\n",(c/d+1)*a-(c/d)*((c/d)+1)/2*d*b);
			else printf("%lld\n",max((e+1)*a-e*(e+1)/2*d*b,(e+2)*a-(e+1)*(e+2)/2*d*b));
		}
	}
	return 0;
}