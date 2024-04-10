#include<bits/stdc++.h>
#define bs 233
#define LL long long
using namespace std;
int n,k,m=200,S_t=0;LL ans;
int l[100002],cnt[200002]={},rk[200002],sa[200002],id[200002],oldrk[200002],px[200002],to[200002],rt[200002],la[200002]={};
LL Hs[200002],pw[200002];
char s[200002];
struct SegTree
{
	int lson[16000002],rson[16000002],sum[16000002];
	inline void build(int k,int l,int r)
	{
		sum[k]=0;
		if(l==r)return ;
		int mid=((l+r)>>1);
		build(lson[k]=(++S_t),l,mid),build(rson[k]=(++S_t),mid+1,r);
	}
	inline void modify(int k,int k1,int l,int r,int x,int d)
	{
		lson[k1]=lson[k],rson[k1]=rson[k],sum[k1]=sum[k]+d;
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)modify(lson[k],lson[k1]=(++S_t),l,mid,x,d);
		else modify(rson[k],rson[k1]=(++S_t),mid+1,r,x,d);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return query(lson[k],l,mid,l1,mid)+query(rson[k],mid+1,r,mid+1,r1);
	}
}S;
inline bool cmp(int x,int y,int w)
{
	return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];
}
inline LL getHs(int l,int r)
{
	return Hs[r]-Hs[l-1]*pw[r-l+1];
}
inline bool cmp1(int z,int x,int y)
{
	int le=0,r=min(l[n]-1-sa[z],y-x),mid;
	while(le<=r)
	{
		mid=((le+r)>>1);
		if(getHs(sa[z],sa[z]+mid)==getHs(x,x+mid))le=mid+1;
		else r=mid-1;
	}
	return (sa[z]+le<=l[n]-1? s[sa[z]+le]:0)>=(x+le<=y? s[x+le]:0);
}
inline bool cmp2(int z,int x,int y)
{
	int le=0,r=min(l[n]-1-sa[z],y-x),mid;
	while(le<=r)
	{
		mid=((le+r)>>1);
		if(getHs(sa[z],sa[z]+mid)==getHs(x,x+mid))le=mid+1;
		else r=mid-1;
	}
	return (sa[z]+le<=l[n]-1? s[sa[z]+le]:200)>=(x+le<=y? s[x+le]:200);//
}
inline bool check(int x,int y)
{
	int le,r,mid,L,R;
	for(le=n+1,r=l[n]-1,mid;le<=r;)
	{
		mid=((le+r)>>1);
		if(cmp1(mid,x,y))r=mid-1;
		else le=mid+1;
	}
	L=le;
	for(le=n+1,r=l[n]-1,mid;le<=r;)
	{
		mid=((le+r)>>1);
		if(cmp2(mid,x,y))r=mid-1;
		else le=mid+1;
	}
	R=r;
	return S.query(rt[R],1,l[n],L,l[n])>=k;
}
int main()
{
	scanf("%d%d",&n,&k),l[0]=pw[0]=1;
	for(int i=1;i<=n;++i)scanf("%s",s+l[i-1]),s[l[i]=l[i-1]+strlen(s+l[i-1])]='#',++l[i];
	--l[n];
	for(int i=1;i<=l[n];++i)++cnt[rk[i]=s[i]],Hs[i]=Hs[i-1]*bs+s[i],pw[i]=pw[i-1]*bs;
	for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
	for(int i=l[n];i;--i)sa[cnt[rk[i]]--]=i;
	for(int w=1,p=0;w<l[n] && p<l[n];w<<=1,m=p)
	{
		p=0;
		for(int i=l[n];i>l[n]-w;--i)id[++p]=i;
		for(int i=1;i<=l[n];++i)if(sa[i]>w)id[++p]=sa[i]-w;
		for(int i=0;i<=m;++i)cnt[i]=0;
		for(int i=1;i<=l[n];++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
		for(int i=l[n];i;--i)sa[cnt[px[i]]--]=id[i];
		for(int i=1;i<=l[n];++i)oldrk[i]=rk[i];
		p=0;
		for(int i=1;i<=l[n];++i)rk[sa[i]]=cmp(sa[i],sa[i-1],w)? p:(++p);
	}
	++l[n];
	for(int i=1;i<=n;++i)for(int j=l[i-1];j<l[i]-1;++j)rk[j]=i;
	S.build(rt[n]=(++S_t),1,l[n]);
	for(int i=n+1,x;i<l[n];++i)
	{
		if(la[rk[sa[i]]])S.modify(rt[i-1],x=(++S_t),1,l[n],la[rk[sa[i]]],-1);
		else x=rt[i-1];
		S.modify(x,rt[i]=(++S_t),1,l[n],la[rk[sa[i]]]=i,1);
	}
	for(int i=1;i<=n;++i)
	{
		ans=0;
		for(int j=l[i-1],k=l[i-1];j<l[i]-1;++j)
		{
			k=max(k,j);
			while(k<l[i]-1)
			{
				if(!check(j,k))break;
				++k;
			}
			ans+=k-j;
		}
		printf("%lld ",ans);
	}
	return 0;
}