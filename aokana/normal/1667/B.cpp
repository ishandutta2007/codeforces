#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10;
int n,t_case;
ll a[maxn],b[maxn],bl,f[maxn],pre[maxn];
struct SGT{
	struct segment_tree{
		int l,r;
		ll v;
	}t[maxn<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	inline void push_up(int p){
		t[p].v=max(t[ls(p)].v,t[rs(p)].v);
	}
	void build(int p,int l,int r){
		t[p].l=l,t[p].r=r;
		if(l==r){
			t[p].v=LLONG_MIN/2;
			return;
		}
		ri mid=l+r>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		push_up(p);
	}
	#define no_intersection (t[p].l>r||l>t[p].r)
	#define is_subseg (l<=t[p].l&&t[p].r<=r)
	void modify(int p,int l,int r,ll v){
		if(no_intersection)return;
		if(is_subseg){
			ckmax(t[p].v,v);
			return;
		}
		modify(ls(p),l,r,v);
		modify(rs(p),l,r,v);
		push_up(p);
	}
	ll query(int p,int l,int r){
		if(no_intersection)return LLONG_MIN/2;
		if(is_subseg)return t[p].v;
		return max(query(ls(p),l,r),query(rs(p),l,r));
	}
}t[3];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		pre[0]=0;
		for(ri i=1;i<=n;++i)scanf("%lld",a+i),pre[i]=pre[i-1]+a[i],b[i]=pre[i];
		b[bl=n+1]=0;
		sort(b+1,b+bl+1);
		bl=unique(b+1,b+bl+1)-b-1;
		clear(f,n,-0x3f);
		f[0]=0,pre[0]=lower_bound(b+1,b+bl+1,pre[0])-b;
		for(ri i=0;i<3;++i){
			t[i].build(1,1,bl);
			t[i].modify(1,pre[0],pre[0],0);
		}
		for(ri i=1;i<=n;++i){
			pre[i]=lower_bound(b+1,b+bl+1,pre[i])-b;
			if(pre[i]>1)ckmax(f[i],t[0].query(1,1,pre[i]-1)+i);
			ckmax(f[i],t[1].query(1,pre[i],pre[i]));
			if(pre[i]<bl)ckmax(f[i],t[2].query(1,pre[i]+1,bl)-i);
			t[0].modify(1,pre[i],pre[i],f[i]-i);
			t[1].modify(1,pre[i],pre[i],f[i]);
			t[2].modify(1,pre[i],pre[i],f[i]+i);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}