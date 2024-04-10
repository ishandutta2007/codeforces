#include<cstdio>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
int n,n1,st_t=0;
int a[300002],b[300002],st[300002]={},f[300002];
LL dp[300002]={},arr[1200002];
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void modify(int k,int l,int r,int x)
{
	if(l==r){arr[k]=dp[x];return ;}
	int mid=((l+r)>>1);
	if(x<=mid)modify(lson(k),l,mid,x);
	else modify(rson(k),mid+1,r,x);
	arr[k]=max(arr[lson(k)],arr[rson(k)]);
}
inline LL query(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return arr[k];
	int mid=((l+r)>>1);
	if(r1<=mid)return query(lson(k),l,mid,l1,r1);
	if(l1>mid)return query(rson(k),mid+1,r,l1,r1);
	return max(query(lson(k),l,mid,l1,mid),query(rson(k),mid+1,r,mid+1,r1));
}
int main()
{
	scanf("%d",&n),n1=(n<<2);
	for(int i=1;i<=n1;++i)arr[i]=-inf;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{
		while(st_t && a[i]<a[st[st_t]])--st_t;
		f[i]=st[st_t],st[++st_t]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(f[i])dp[i]=dp[f[i]];else dp[i]=b[i];
		if(max(f[i],1)<=i-1)dp[i]=max(dp[i],query(1,1,n,max(f[i],1),i-1)+b[i]);
		modify(1,1,n,i);
	}
	printf("%lld",dp[n]);
	return 0;
}//