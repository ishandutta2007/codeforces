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
const int N=35009;
int n,k,a[N],dp[59][N],pre[N],tot[N];
int tree[N<<2],lazy[N<<2];
inline int lc(int x){return x<<1;}
inline int rc(int x){return x<<1|1;}
inline void push_up(int x)
{
	tree[x]=max(tree[x<<1],tree[x<<1|1]);
}
inline void push_down(int x)
{
	if(lazy[x])
	{
		lazy[lc(x)]+=lazy[x],lazy[rc(x)]+=lazy[x];
		tree[lc(x)]+=lazy[x],tree[rc(x)]+=lazy[x];
		lazy[x]=0;
	}
}
inline void build(int l,int r,int p,int pos)
{
	lazy[p]=0;
	if(l==r)
	{
		tree[p]=dp[pos][l-1];//cout<<l<<" "<<r<<" "<<p<<" "<<tree[p]<<endl;
		return ;
	}
	build(l,mid,lc(p),pos);
	build(mid+1,r,rc(p),pos);
	push_up(p);
}
inline void update(int l,int r,int p,int k,int L,int R)
{
	if(L<=l&&r<=R)
	{
		tree[p]++,lazy[p]++;//cout<<l<<" "<<r<<" "<<p<<" "<<tree[p]<<"cmll02"<<endl;
		return ;
	}
	push_down(p);
	if(mid>=L)update(l,mid,lc(p),k,L,R);
	if(mid<R)update(mid+1,r,rc(p),k,L,R);
	push_up(p);
	return ;
}
inline int query(int l,int r,int p,int L,int R)
{
	if(L<=l&&r<=R)return tree[p];
	int res=0;
	push_down(p);
	if(mid>=L)res=max(res,query(l,mid,lc(p),L,R));
	if(mid<R)res=max(res,query(mid+1,r,rc(p),L,R));
	return res;
}
inline void init()
{
	for(int i=1;i<=n;i++)
		pre[i]=tot[a[i]]+1,tot[a[i]]=i;
}
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	init();
	for(int i=1;i<=k;i++)
	{
		build(1,n,1,i-1);//cout<<"---------------------"<<endl;for(int k=8;k<=13;k++)cout<<k-7<<" "<<tree[k]<<endl;
		for(int j=1;j<=n;j++)
		{
		//	cout<<tree[8]<<endl;
			update(1,n,1,1,pre[j],j);
		//	cout<<tree[8]<<endl;
			dp[i][j]=query(1,n,1,1,j);
			//for(int k=8;k<=13;k++)cout<<k-7<<" "<<tree[k]<<endl;
			//cout<<i<<" "<<j<<" "<<pre[j]<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}
//dp[i][j]=dp[k][j-1]+cost[k+1][i]; 
// k  dp[k][j-1]+cost[k+1][i]