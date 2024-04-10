#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
struct segment_tree{
	int l,r,v1,v2,tag1,tag2;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	if(t[rs(p)].v1>t[ls(p)].v1)t[p].v1=t[rs(p)].v1,t[p].v2=t[rs(p)].v2;
	else t[p].v1=t[ls(p)].v1,t[p].v2=t[ls(p)].v2;
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
inline void add_tag(int p,int v1,int v2){
	if(v1<=t[p].tag1)return;
	t[p].v1=t[p].tag1=v1,t[p].v2=t[p].tag2=v2;
}
inline void push_down(int p){
	if(!t[p].tag1)return;
	add_tag(ls(p),t[p].tag1,t[p].tag2);
	add_tag(rs(p),t[p].tag1,t[p].tag2);
	t[p].tag1=t[p].tag2=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v1,int v2){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v1,v2);
		return;
	}
	push_down(p);
	modify(ls(p),l,r,v1,v2);
	modify(rs(p),l,r,v1,v2);
	push_up(p);
}
typedef pair<int,int> pii;
#define fi first
#define se second
inline pii query(int p,int l,int r){
	if(no_intersection)return {0,0};
	if(is_subset)return {t[p].v1,t[p].v2};
	push_down(p);
	pii tmp1=query(ls(p),l,r),tmp2=query(rs(p),l,r);
	return (tmp2.fi>tmp1.fi)?tmp2:tmp1;
}
int a[maxn][3],b[maxn],bl,m,n,pre[maxn],t_case;
vector<pii>pos[maxn];
#define pb push_back
#define ALL(k) k.begin(),k.end()
bool vis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",&a[i][2],&a[i][0],&a[i][1]);
		b[++bl]=a[i][0],b[++bl]=a[i][1];
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	build(1,1,bl);
	for(ri i=1;i<=m;++i){
		a[i][0]=lower_bound(b+1,b+bl+1,a[i][0])-b;
		a[i][1]=lower_bound(b+1,b+bl+1,a[i][1])-b;
		pos[a[i][2]].pb({a[i][0],a[i][1]});
	}
	ri ans1=0,ans2=0;
	for(ri i=1;i<=n;++i){
		pii mx={0,0};
		for(auto j:pos[i]){
			pii tmp=query(1,j.fi,j.se);
			if(tmp.fi>mx.fi)mx=tmp;
		}
		++mx.fi;
		pre[i]=mx.se;
		if(mx.fi>ans1)ans1=mx.fi,ans2=i;
		for(auto j:pos[i])modify(1,j.fi,j.se,mx.fi,i);
	}
	for(ri i=ans2;i;i=pre[i])vis[i]=true;
	printf("%d\n",n-ans1);
	for(ri i=1;i<=n;++i)
		if(!vis[i])
			printf("%d ",i);
	return 0;
}