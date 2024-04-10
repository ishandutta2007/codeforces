#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,S_t;
bool ok=1;
int sx[50002],sy[50002],ex[50002],ey[50002];
struct aaa
{
	int x,l,r,o;
}opt[100002];
inline bool cmp(aaa a,aaa b)
{
	return a.x<b.x? 1:0;
}
struct bbb
{
	int mn;
	bool sg;
};
inline bbb merge(bbb a,bbb b)
{
	if(a.mn<b.mn)return a;
	if(a.mn>b.mn)return b;
	return a.sg^=b.sg,a;
}
struct SegTree
{
	int lson[10000002],rson[10000002],laz[10000002];
	bbb a[10000002];
	inline int newnode(bool o)
	{
		return a[++S_t]=(bbb){0,o},lson[S_t]=rson[S_t]=laz[S_t]=0,S_t;
	}
	inline void pushdown(int k)
	{
		if(laz[k])a[lson[k]].mn+=laz[k],laz[lson[k]]+=laz[k],a[rson[k]].mn+=laz[k],laz[rson[k]]+=laz[k],laz[k]=0;
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)return (void)(a[k].mn+=d,laz[k]+=d);
		int mid=((l+r)>>1);
		if(!lson[k])lson[k]=newnode((l^(mid+1))&1);
		if(!rson[k])rson[k]=newnode((mid^r)&1);
		pushdown(k);
		if(l1<=mid)modify(lson[k],l,mid,l1,r1,d);
		if(r1>mid)modify(rson[k],mid+1,r,l1,r1,d);
		a[k]=merge(a[lson[k]],a[rson[k]]);
	}
}S;
inline void up(int &x)
{
	(++x)>>=1;
}
inline void down(int &x)
{
	x>>=1;
}
inline bool solve()
{
	S_t=0,S.newnode(n&1);
	for(int i=1;i<=m;++i)opt[(i<<1)-1]=(aaa){sx[i],sy[i],ey[i],1},opt[i<<1]=(aaa){ex[i]+1,sy[i],ey[i],-1},up(sx[i]),up(sy[i]),down(ex[i]),down(ey[i]);
	m<<=1,sort(opt+1,opt+m+1,cmp);
	for(int i=1,j;i<=m;i=j)
	{
		for(j=i;j<=m && opt[j].x==opt[i].x;++j)S.modify(1,1,n,opt[j].l,opt[j].r,opt[j].o);
		if((n^(S.a[1].mn? 0:S.a[1].sg))&1)ok^=(opt[j].x^opt[i].x)&1;
	}
	return m>>=1,ok;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),k=log2(k);
	for(int i=1;i<=m;++i)scanf("%d%d%d%d",&sx[i],&sy[i],&ex[i],&ey[i]);
	for(;~(k--);)if(!solve())return 0&puts("Hamed");
	return 0&puts("Malek");
}