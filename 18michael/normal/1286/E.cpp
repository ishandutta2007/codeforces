#include<bits/stdc++.h>
#define LL __int128
#define inf 0x40000000
using namespace std;
int n,t;
LL ans=0,res=0;
char c[600002];
int w[600002],nx[600002];
int la[600002][26];
set<int> s;
map<int,int> mp;
map<int,int>::iterator it;
template<class T>void write(T x)
{
	if(x>9)write(x/10);
	putchar((x%10)^48);
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	int mn[2400002];
	inline void build(int k,int l,int r)
	{
		mn[k]=inf;if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r)return (void)(mn[k]=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		mn[k]=min(mn[ls],mn[rs]);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return mn[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return min(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
int main()
{
	scanf("%d",&n),S.build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		do c[i]=getchar();while(c[i]<'a' || c[i]>'z');
		scanf("%d",&w[i]),c[i]=((c[i]-'a'+ans)%26),S.modify(1,1,n,i,w[i]^=(ans&(inf-1)));
		for(nx[i]=nx[i-1];nx[i] && c[nx[i]+1]!=c[i];nx[i]=nx[nx[i]]);
		if(nx[i]+1<i && c[nx[i]+1]==c[i])++nx[i];
		for(int j=0;j<26;++j)la[i][j]=la[nx[i]][j];
		if(nx[i])la[i][c[nx[i]+1]]=nx[i];
		for(int j=0;j<26;++j)if(c[i]!=j)for(int k=la[i-1][j];k && s.count(i-k);k=la[k][j])res-=(t=S.query(1,1,n,i-k,i-1)),--mp[-t],s.erase(i-k);
		for(it=mp.begin();it!=mp.end() && -(*it).first>w[i];it=mp.erase(it))res+=(LL)((*it).first+w[i])*(*it).second,mp[-w[i]]+=(*it).second;
		if(c[i]==c[1])s.insert(i),++mp[-w[i]],res+=w[i];
		write(ans+=res),putchar('\n');
	}
	return 0;
}