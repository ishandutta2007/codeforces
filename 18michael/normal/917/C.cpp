#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int PMX=26;
const LL inf=0x3f3f3f3f3f3f3f3f;
int m,k,n,q,Mx,t=0,now;
LL sum=0;
int c[12],one[262],to[262],st[72];
struct aaa
{
	int num;
	LL w;
}sp[32];
struct bbb
{
	LL a[72][72];
}Mat[32],ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.num<b.num? 1:0;
}
inline bbb mul(bbb a,bbb b)
{
	bbb c;
	for(int i=1;i<=t;++i)
		for(int j=1;j<=t;++j)
		{
			c.a[i][j]=inf;
			for(int k=1;k<=t;++k)
				c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
		}
	return c;
}
inline bbb Pow(int b)
{
	bbb c=Mat[0];--b;
	for(int i=0;i<=PMX;++i)if((b>>i)&1)c=mul(c,Mat[i]);
	return c;
}
int main()
{
	read(m),read(k),read(n),read(q),Mx=(1<<k),now=1;
	for(int i=1;i<Mx;++i)one[i]=one[(i>>1)]+(i&1);
	for(int i=1;i<=k;++i)read(c[i]);
	for(int i=1;i<=q;++i)read(sp[i].num),read(sp[i].w);
	sort(sp+1,sp+q+1,cmp);
	for(int i=0;i<Mx;++i)if(one[i]==m)st[to[i]=(++t)]=i;
	for(int i=1;i<=t;++i)
		for(int j=1;j<=t;++j)
			Mat[0].a[i][j]=ans.a[i][j]=inf;
	for(int i=1;i<=t;++i)ans.a[i][i]=0;
	for(int i=1,l,w;i<=t;++i)
	{
		l=((st[i]<<1)&(Mx-1));
		if(one[l]==m)Mat[0].a[i][to[l]]=0;
		else for(int j=k-1;~j;--j)if(!((l>>j)&1))Mat[0].a[i][to[l|(1<<j)]]=c[k-j];
	}
	for(int i=1;i<=PMX;++i)Mat[i]=mul(Mat[i-1],Mat[i-1]);
	for(int i=1;i<=q;++i)
	{
		if(sp[i].num>n-m){sum+=sp[i].w;continue;}
		ans=mul(ans,Pow(sp[i].num-now)),now=sp[i].num;
		for(int j=1;j<=t;++j)
			for(int l=1;l<=t;++l)
				if((st[l]>>(k-1))&1)
					ans.a[j][l]+=sp[i].w;
	}
	if(n-m+1-now>0)ans=mul(ans,Pow(n-m+1-now));
	printf("%lld",ans.a[t][t]+sum);
	return 0;
}