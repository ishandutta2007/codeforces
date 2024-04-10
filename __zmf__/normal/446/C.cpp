//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
#define mid ((l+r)>>1)
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=3e5+9,mod=1e9+9;
int a[N],fib[N],n,m,nfib[N],pre[N];
struct point
{
	int lazy1,lazy2;
	int sum;
	int pre1,pre2;
}tree[N<<2];
inline int lc(int p){return p<<1;}
inline int rc(int p){return p<<1|1;}
inline void push_up(int p)
{
	tree[p].sum=(tree[lc(p)].sum+tree[rc(p)].sum)%mod;
	tree[p].pre1=(tree[lc(p)].pre1+tree[rc(p)].pre1)%mod;
	tree[p].pre2=(tree[lc(p)].pre2+tree[rc(p)].pre2)%mod;
	return ;
}
inline void get1(int l,int r,int k,int p)
{
	tree[p].lazy1=(tree[p].lazy1+k)%mod;
	tree[p].sum=(tree[p].sum+k*tree[p].pre1%mod)%mod;
}
inline void get2(int l,int r,int k,int p)
{
	tree[p].lazy2=(tree[p].lazy2+k)%mod;
	tree[p].sum=(tree[p].sum+k*tree[p].pre2%mod)%mod;
}
inline void push_down(int l,int r,int p)
{
	if(tree[p].lazy1)
	{
		get1(l,mid,tree[p].lazy1,lc(p));
		get1(mid+1,r,tree[p].lazy1,rc(p));
		tree[p].lazy1=0;
	}
	if(tree[p].lazy2)
	{
		get2(l,mid,tree[p].lazy2,lc(p));
		get2(mid+1,r,tree[p].lazy2,rc(p));
		tree[p].lazy2=0;
	}
}
inline void build(int l,int r,int p)
{
	if(l==r)
	{
		tree[p].pre1=fib[l+1];
		tree[p].pre2=fib[l];
		tree[p].sum=a[l];
		return ;
	}
	build(l,mid,lc(p));
	build(mid+1,r,rc(p));
	push_up(p);
	//cout<<l<<" "<<r<<" "<<tree[p].pre1<<" "<<tree[p].pre2<<" "<<tree[p].sum<<endl;
}
inline void update(int l,int r,int p,int L,int R,int tag1,int tag2)
{
	if(L<=l&&r<=R)
	{
		tree[p].lazy1=(tree[p].lazy1+tag1)%mod;
		tree[p].lazy2=(tree[p].lazy2+tag2)%mod;
		tree[p].sum=(tree[p].sum+tree[p].pre1*tag1%mod+tree[p].pre2*tag2%mod)%mod;
		return ;
	}
	push_down(l,r,p);
	if(mid>=L)update(l,mid,lc(p),L,R,tag1,tag2);
	if(mid<R)update(mid+1,r,rc(p),L,R,tag1,tag2);
	push_up(p);
}
inline int query(int l,int r,int p,int L,int R)
{
	if(L<=l&&r<=R)return tree[p].sum;
	push_down(l,r,p);
	int res=0;
	if(mid>=L)res+=query(l,mid,lc(p),L,R);
	if(mid<R)res+=query(mid+1,r,rc(p),L,R);
	return res%mod;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	fib[1]=nfib[1]=1;
	fib[2]=1;nfib[2]=mod-1;
	//pre[0]=1;pre[1]=2;
	for(int i=3;i<=n+1;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	//	pre[i]=(pre[i-1]+fib[i])%mod;
		if(i&1)nfib[i]=fib[i];
		else nfib[i]=(mod-fib[i])%mod;
	}
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int opt=read(),l=read(),r=read();
		if(opt==1)update(1,n,1,l,r,nfib[l-1],nfib[l]);
		else printf("%lld\n",query(1,n,1,l,r)%mod);
	}
	return 0;
}//f_{x-l+1}=f_{x+1}f_{-l+1}+f_{x}f_{-l}