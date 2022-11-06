//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9;
struct Tree
{
	int sum[N<<2],lazy[N<<2]; 
}tree[39];
inline int lc(int x){return x<<1;}
inline int rc(int x){return x<<1|1;}
int n,m,l,r;
char kk[N];
int a[N],val[39],od;
inline void push_up(int id,int x)
{
	tree[id].sum[x]=tree[id].sum[lc(x)]+tree[id].sum[rc(x)];
}
inline void push_down(int id,int l,int r,int p)
{
	if(tree[id].lazy[p]!=-1)
	{
		tree[id].lazy[lc(p)]=tree[id].lazy[p];
		tree[id].lazy[rc(p)]=tree[id].lazy[p];
		tree[id].sum[lc(p)]=(mid-l+1)*tree[id].lazy[p];
		tree[id].sum[rc(p)]=(r-mid)*tree[id].lazy[p];
		//cout<<tree[id].sum[lc(p)]<<" "<<tree[id].sum[rc(p)]<<" "<<l<<" "<<mid<<" "<<mid+1<<" "<<r<<endl;
		tree[id].lazy[p]=-1;
	}
	return ;
}
inline void build(int id,int l,int r,int p)
{
	tree[id].lazy[p]=-1;
	if(l==r)
	{
	//	if(a[l]==id)cout<<l<<" "<<a[l]<<endl;
		if(a[l]==id)tree[id].sum[p]=1;
		else tree[id].sum[p]=0;return ;
	}
	build(id,l,mid,lc(p));
	build(id,mid+1,r,rc(p));
	push_up(id,p);
}
inline int query(int id,int l,int r,int p,int L,int R)
{
	int res=0;
	if(L<=l&&r<=R)return tree[id].sum[p];
	push_down(id,l,r,p);
	if(mid>=L)res+=query(id,l,mid,lc(p),L,R);
	if(mid<R)res+=query(id,mid+1,r,rc(p),L,R);
	return res;
}
inline void update(int id,int l,int r,int p,int L,int R,int val)
{
	if(L<=l&&r<=R)
	{
		tree[id].lazy[p]=val;tree[id].sum[p]=(r-l+1)*val;
		return ;
	}
	push_down(id,l,r,p);
	if(mid>=L)update(id,l,mid,lc(p),L,R,val);
	if(mid<R)update(id,mid+1,r,rc(p),L,R,val);
	push_up(id,p);
	return ;
}
int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),m=read();
	cin>>kk;
	for(int i=1;i<=n;i++)a[i]=(int)(kk[i-1]-'a'+1);
	for(int i=1;i<=26;i++)
	{
		build(i,1,n,1);
	}
	for(int i=1;i<=m;i++)
	{
		l=read(),r=read(),od=0;
		for(int j=1;j<=26;j++)val[j]=query(j,1,n,1,l,r);
		for(int j=1;j<=26;j++)
			if(val[j]&1)
			{
				od++;//cout<<val[j]<<endl;	
			}
		if(od>1)continue;
		for(int j=1;j<=26;j++)
			update(j,1,n,1,l,r,0);
		if(od==1)
		{
			for(int j=1;j<=26;j++)
				if(val[j]%2==1)
				{
				//	cout<<(l+r)/2<<endl;
					val[j]--;update(j,1,n,1,(l+r)/2,(l+r)/2,1);
				}
		}
		for(int j=1;j<=26;j++)val[j]=val[j]/2;
		int L=l,R=r;
		for(int j=1;j<=26;j++)
			if(val[j])
			{
			//	cout<<L+val[j]-1<<" "<<R-val[j]+1<<endl;
				update(j,1,n,1,L,L+val[j]-1,1);update(j,1,n,1,R-val[j]+1,R,1);
				L+=val[j],R-=val[j];
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=26;j++)
			if(query(j,1,n,1,i,i))
			{
				putchar(j+'a'-1);break;
			}
	return 0;
}
/*
10 3
rrrrrrrrrr
2 8
5 8
3 10
*/