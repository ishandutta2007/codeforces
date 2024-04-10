#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k,ob,oc,Test_num;
LL b,c;
int a[1000002];
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
		read(n),read(m),read(k),b=c=ob=oc=0;
		for(int i=1;i<=k;++i)
		{
			read(a[i]);
			if(a[i]/n>1)
			{
				b+=a[i]/n;
				ob|=(a[i]/n>2);
			}
			if(a[i]/m>1)
			{
				c+=a[i]/m;
				oc|=(a[i]/m>2);
			}
		}
		puts((b>=m && (!(m&1) || ob)) || (c>=n && (!(n&1) || oc))? "Yes":"No");
	}
	return 0;
}