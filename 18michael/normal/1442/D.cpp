#include<cstdio>
#include<vector>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,K;LL ans=0;
int len[3002];
LL a[3002][3002];
LL f[3002][14];
vector<int> vec[12002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL max(LL x,LL y)
{
	return x>y? x:y;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void add(int k,int l,int r,int l1,int r1,int d)
{
	if(l1>r1)return ;
	if(l>=l1 && r<=r1){vec[k].push_back(d);return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(r1<=mid)add(ls,l,mid,l1,r1,d);
	else if(l1>mid)add(rs,mid+1,r,l1,r1,d);
	else add(ls,l,mid,l1,mid,d),add(rs,mid+1,r,mid+1,r1,d);
}
inline void solve(int k,int l,int r,int d)
{
	for(int i=0;i<=K;++i)f[i][d]=f[i][d-1];
	for(int i=0;i<vec[k].size();++i)for(int j=K;j>=len[vec[k][i]];--j)f[j][d]=max(f[j][d],f[j-len[vec[k][i]]][d]+a[vec[k][i]][len[vec[k][i]]]);
	if(l==r)
	{
		for(int i=0;i<=len[l];++i)ans=max(ans,f[K-i][d]+a[l][i]);
		return ;
	}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	solve(ls,l,mid,d+1),solve(rs,mid+1,r,d+1);
}
int main()
{
	read(n),read(K),f[0][0]=0;
	for(int i=1;i<=K;++i)f[i][0]=-inf;
	for(int i=1;i<=n;++i)
	{
		read(len[i]);
		for(int j=1;j<=len[i];++j)
		{
			read(a[i][j]);
			if(j<=K)a[i][j]+=a[i][j-1];
			else --j,--len[i];
		}
		add(1,1,n,1,i-1,i),add(1,1,n,i+1,n,i);
	}
	solve(1,1,n,1);
	return 0&printf("%lld",ans);
}