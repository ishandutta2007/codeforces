#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxm=11,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxm][maxn],m,n;
struct node{
	int cnt,mx,l[maxm],pos,r[maxm];
	inline node(){pos=0;}
	inline node operator+(const node &k)const{
		if(!pos)return k;
		if(!k.pos)return *this;
		vector<int>fa(mx+k.mx+1);
		iota(fa.begin(),fa.end(),0);
		function<int(int)>find=[&](int k){return k==fa[k]?k:fa[k]=find(fa[k]);};
		auto merge=[&](int x,int y){
			if(x>y)swap(x,y);
			ri fx=find(x),fy=find(y);
			if(fx!=fy){fa[fy]=fx;return true;}
			return false;
		};
		node ret;
		ret.cnt=cnt+k.cnt;
		for(ri i=1;i<=m;++i)
			if(a[i][pos]==a[i][pos+1])
				ret.cnt-=merge(r[i],k.l[i]+mx);
		vector<int>id(fa.size());
		ret.mx=0;
		for(ri i=1;i<=m;++i){
			ret.l[i]=find(l[i]);
			if(!id[ret.l[i]])id[ret.l[i]]=++ret.mx;
			ret.l[i]=id[ret.l[i]];
			ret.r[i]=find(k.r[i]+mx);
			if(!id[ret.r[i]])id[ret.r[i]]=++ret.mx;
			ret.r[i]=id[ret.r[i]];
		}
		ret.pos=k.pos;
		return ret;
	}
};
struct segment_tree{
	int l,r;
	node v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].v.cnt=0,t[p].v.pos=l;
		for(ri i=1;i<=m;++i){
			if(a[i][l]!=a[i-1][l])++t[p].v.cnt;
			t[p].v.l[i]=t[p].v.r[i]=t[p].v.cnt;
		}
		t[p].v.mx=t[p].v.cnt;
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].v=t[ls(p)].v+t[rs(p)].v;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subseg (l<=t[p].l&&t[p].r<=r)
node query(int p,int l,int r){
	if(no_intersection)return node();
	if(is_subseg)return t[p].v;
	return query(ls(p),l,r)+query(rs(p),l,r);
}
int q;
int main(){
	scanf("%d%d%d",&m,&n,&q);
	for(ri i=1;i<=m;++i)
		for(ri j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	build(1,1,n);
	while(q--){
		ri l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,l,r).cnt);
	}
	return 0;
}