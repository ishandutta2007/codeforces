#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
const int B=550;
const int m=300000;
int n;
int bel[N],nn;
LL s1[N],s2[N];
LL s3[N],s4[N];
int L[N],R[N];
void add (int x)
{
	int now=bel[x];
	for (int u=x;u<=R[now];u++)	{s3[u]+=x;s4[u]++;}
	for (int u=now+1;u<=nn;u++)	{s1[u]+=x;s2[u]++;}
}
LL query (int x)
{
	if (x<=0) return 0;
	int t=bel[x];
	return s1[t]+s3[x];
}
LL q1 (int l,int r)
{
	if (l>r) return 0;
	return query(r)-query(l-1);
}
LL query1 (int x)
{
	int t=bel[x];
	return s2[t]+s4[x];
}
LL q2 (int l,int r)
{
	if (l>r) return 0;
	return query1(r)-query1(l-1);
}
LL ans;
LL f[N];
void solve1 (int x)
{
	//printf("A\n");
	if (x>=B)
	{
		ans=ans+q1(1,x);
		for (int u=1;u*x<=m;u++)
		{
			int l=u*x;
			int r=min((u+1)*x-1,m);
			LL t1=q1(l,r);
			LL t2=q2(l,r);
			ans=ans+t1-t2*x*u;
		}
	}
	else ans=ans+f[x];
}
void solve2 (int x)
{
	ans=ans+q2(x+1,m)*x;
	int i;
	for (int u=1;u<=x;u=i+1)
	{
		i=x/(x/u);
		LL t2=q2(u,i);
		LL t1=q1(u,i);
		ans=ans+t2*x-t1*(x/u);
	}
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	bel[0]=1;
	for (int u=1;u<=m;u++)
	{
		bel[u]=bel[u-1];
		if (u%B==0) bel[u]++;
	}
	nn=bel[m];
	for (int u=1;u<=m;u++)	R[bel[u]]=u;
	for (int u=m;u>=1;u--)	L[bel[u]]=u;
	//scanf("%d",&n);
	n=read();
	ans=0;
	for (int u=1;u<=n;u++)
	{
		int x=read();
		solve1(x);
		solve2(x);
		add(x);
		for (int i=1;i<B;i++)  f[i]=f[i]+(x%i);
		printf("%lld ",ans);
	}
	return 0;
}