#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=300005;
LL n,m;
LL K[N],B[N],tot;
LL b,s;
LL read ()
{
    char ch=getchar();LL x=0;
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9')    {x=x*10+ch-'0';ch=getchar();}
    return x;
}
bool check ()
{
	double x=(double)(B[tot]-B[tot-1])/(K[tot-1]-K[tot]);
	double xx=(double)(B[tot-1]-B[tot-2])/(K[tot-2]-K[tot-1]);
	//[x,MAX]    [-MAX,xx]
	return x>=xx;
}
void rebt ()
{
	while (tot>=3&&check())	{tot--;K[tot]=K[tot+1];B[tot]=B[tot+1];}
}
void solve ()
{
/*	printf("s:%lld b:%lld\n",s,b);
	for (int u=1;u<=tot;u++)
		printf("%lld %lld\n",K[u],B[u]);*/
	while (tot>=2)
	{
		if (s*(K[tot]-K[tot-1])>=(B[tot-1]-B[tot])) 
		{
			tot--;
		}
		else break;
	}
	printf("%lld %lld\n",K[tot]+1,s*K[tot]+B[tot]+b);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	tot++;K[tot]=0;B[tot]=0;
	while (m--)
	{
		LL op,nn;
		op=read();
		if (op==1) 
		{
			nn=read();
			tot=1;K[tot]=0;B[tot]=0;
			b=0;s=0;
			n=n+nn;
		}
		else if (op==2)
		{
			nn=read();
			tot++;
			K[tot]=n;
			B[tot]=-b-s*n;
			n+=nn;
			rebt();
		}
		else
		{
			b=b+read();
			s=s+read();
		}
		solve();
	}
	return 0;
}