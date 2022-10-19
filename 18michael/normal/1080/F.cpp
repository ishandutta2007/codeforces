#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,S_t=0;
int l[300002],r[300002],p[300002],id[300002],rt[300002];
struct SegTree
{
	int mx[12000002],lson[12000002],rson[12000002];
	inline void modify(int k,int k1,int l,int r,int x,int d)
	{
		if(l==r){mx[k1]=(k? min(mx[k],d):d);return ;}
		int mid=((l+r)>>1);
		if(x<=mid)modify(lson[k],lson[k1]=(++S_t),l,mid,x,d),rson[k1]=rson[k];
		else modify(rson[k],rson[k1]=(++S_t),mid+1,r,x,d),lson[k1]=lson[k];
		mx[k1]=((lson[k1] && rson[k1])? max(mx[lson[k1]],mx[rson[k1]]):inf);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return inf;
		if(l>=l1 && r<=r1)return mx[k];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return max(query(lson[k],l,mid,l1,mid),query(rson[k],mid+1,r,mid+1,r1));
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return l[x]<l[y]? 1:0;
}
int main()
{
	read(n),read(m),read(k),rt[k+1]=0;
	for(int i=1;i<=k;++i)read(l[i]),read(r[i]),read(p[i]),id[i]=i;
	sort(id+1,id+k+1,cmp);
	for(int i=k;i;--i)S.modify(rt[i+1],rt[i]=(++S_t),1,n,p[id[i]],r[id[i]]);
	for(int a,b,x,y,L,R,mid;m--;)
	{
		read(a),read(b),read(x),read(y);
		for(L=1,R=k;L<=R;)
		{
			mid=((L+R)>>1);
			if(l[id[mid]]>=x)R=mid-1;
			else L=mid+1;
		}
		puts((L>k || S.query(rt[L],1,n,a,b)>y)? "no":"yes"),fflush(stdout);
	}
	return 0;
}