#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
typedef long long LL;
const LL g=5; 
const LL M=1e9+7;
const LL MM=1e9+6;
LL add (LL x,LL y,LL MOD)   {x=x+y;return x>=MOD?x-MOD:x;}
LL mul (LL x,LL y,LL MOD)   {return (LL)x*y%MOD;}
LL dec (LL x,LL y,LL MOD)   {x=x-y;return x<0?x+MOD:x;}
LL Pow (LL x,LL y,LL MOD)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=Pow(x,y>>1,MOD);
	lalal=mul(lalal,lalal,MOD);
	if (y&1) lalal=mul(lalal,x,MOD);
	return lalal;
}
LL n,f1,f2,f3,c;
map<int,int> mp;
LL inv (LL x)	{return Pow(x,M-2,M);}
LL BSGS (LL A,LL B)
{
	mp.clear();
	LL m=sqrt(M),p=1;
	for (LL u=0;u<m;u++)	{mp[p]=u;if (p==B) return u;p=mul(p,A,M);}
	LL now=p;
	for (LL u=1;u<=m;u++)
	{
		if (mp.find(mul(B,inv(now),M))!=mp.end()) return u*m+mp[mul(B,inv(now),M)];
		now=mul(now,p,M);
	}
}
struct qq
{
	LL s[5][5];
	void clear ()
	{
		memset(s,0,sizeof(s));
	}
	void prLL ()
	{
		for (LL u=0;u<=4;u++)
		{
			for (LL i=0;i<=4;i++)	printf("%lld ",s[u][i]);
			printf("\n");
		}
	}
};
qq operator * (qq a,qq b)
{
    qq c;
    for (LL u=0;u<=4;u++)
        for (LL i=0;i<=4;i++)
        {
            c.s[u][i]=0;
            for (LL j=0;j<=4;j++)
                c.s[u][i]=add(c.s[u][i],mul(a.s[j][i],b.s[u][j],MM),MM);
        }
    return c;
};
qq calc (qq x,LL y)
{
	if (y==1) return x;
	qq lalal=calc(x,y>>1);
	lalal=lalal*lalal;
	if (y&1) lalal=lalal*x;
	return lalal;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&f1,&f2,&f3,&c);
	f1=BSGS(g,f1);f2=BSGS(g,f2);f3=BSGS(g,f3);
	//printf("%lld %lld %lld\n",Pow(g,f1),Pow(g,f2),Pow(g,f3));
	LL d=BSGS(g,c);
	//printf("%lld %lld\n",Pow(g,d,M),Pow(g,add(d,d,MM),M));
	qq a;
	a.clear();
	a.s[0][1]=1;a.s[1][2]=1;
	a.s[2][0]=a.s[2][1]=a.s[2][2]=a.s[2][3]=1;
	a.s[3][3]=1;a.s[3][4]=add(d,d,MM);
	a.s[4][4]=1;
	a=calc(a,n-3);
	
	LL ans=0;
	ans=add(ans,mul(f1,a.s[2][0],MM),MM);
	ans=add(ans,mul(f2,a.s[2][1],MM),MM);
	ans=add(ans,mul(f3,a.s[2][2],MM),MM);
//	printf("%lld\n",Pow(g,ans,M));
	ans=add(ans,mul(add(d,d,MM),a.s[2][3],MM),MM);
	//printf("%lld %lld %lld\n",Pow(g,ans,M),Pow(g,add(d,d,MM),M),a.s[2][4]);
	ans=add(ans,a.s[2][4],MM);
	printf("%lld\n",Pow(g,ans,M));
	return 0;
}