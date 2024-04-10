#include<bits/stdc++.h>
#define LL long long
#define Mx 1000000000
using namespace std;
int n,Test_num,ok;
LL res;
int a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL gcd(LL x,LL y)
{
	return y? gcd(y,x%y):x;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),res=1,ok=1;
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			if(res<=Mx)res=res*(i+1)/gcd(res,i+1);
			if(res<=Mx && !(a[i]%res))ok=0;
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}