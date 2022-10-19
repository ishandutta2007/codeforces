#include<bits/stdc++.h>
#define Mx 31623
#define LL long long
using namespace std;
int q,q1,Test_num;
LL p,t,mx;
bool u[31632]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	for(int i=2;i<=Mx;++i)
		if(!u[i])
			for(int j=i*i;j<=Mx;j+=i)
				u[j]=1;
	read(Test_num);
	while(Test_num--)
	{
		read(p),read(q);
		if(p%q)
		{
			printf("%lld\n",p);
			continue;
		}
		mx=0,q1=q;
		for(int i=2;i*i<=q1;++i)
			if(!u[i] && !(q%i))
			{
				t=p/q;
				while(!(t%i))t/=i;
				mx=max(mx,t*q/i);
				do q1/=i;while(!(q1%i));
			}
		if(q1>1)
		{
			t=p/q;
			while(!(t%q1))t/=q1;
			mx=max(mx,t*q/q1);
		}
		printf("%lld\n",mx);
	}
	return 0;
}