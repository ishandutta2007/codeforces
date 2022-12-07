#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
const int MOD=998244353;
const int Inv2=499122177;
const int Inv4=748683265;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int n,k,m;
int X,Y,Z;
int s1,s2,s3,s4;
int tot=0;
int A[N],B[N],C[N];
int tmp[N];
void FWT (int *a,int nn,int o)
{
    for (int u=1;u<=nn;u<<=1)
    {
        for (int i=0;i<=nn;i++) tmp[i]=0;
        for (int i=0;i<=nn;i++)
        {
            if (i&u) tmp[i]=dec(tmp[i],a[i]),tmp[i^u]=add(tmp[i^u],a[i]);
            else tmp[i]=add(tmp[i],a[i]),tmp[i^u]=add(tmp[i^u],a[i]);
        }
        for (int i=0;i<=nn;i++)  {a[i]=tmp[i];if (o==-1)a[i]=mul(a[i],Inv2);}
    }
}
int f[N];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d%d%d",&X,&Y,&Z);
	m=(1<<k)-1;
	s1=add(add(X,Y),Z);s2=dec(add(X,Y),Z);s3=add(dec(X,Y),Z);s4=dec(dec(X,Y),Z);
	for (int u=1;u<=n;u++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		tot^=a;
		A[a^b]++;B[a^c]++;C[b^c]++;
	}
	FWT(A,m,1);FWT(B,m,1);FWT(C,m,1);
	for (int u=0;u<=m;u++)
	{
		int a=mul(Inv4,add(add(n,A[u]),add(B[u],C[u])));
		int b=mul(Inv4,dec(add(n,A[u]),add(B[u],C[u])));
		int c=mul(Inv4,dec(add(n,B[u]),add(A[u],C[u])));
		int d=mul(Inv4,dec(add(n,C[u]),add(A[u],B[u])));
		f[u]=mul(mul(Pow(s1,a),Pow(s2,b)),mul(Pow(s3,c),Pow(s4,d)));
	}
	FWT(f,m,-1);
	for (int u=0;u<=m;u++) printf("%d ",f[u^tot]);
	return 0;
}