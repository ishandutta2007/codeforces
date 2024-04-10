#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int d[3][4]={{1,1,3,3},{0,2,2,3},{0,1,-1,-1}},maxa=4,maxn=1e5+10;
typedef int mat[maxa][maxa];
inline void mul(mat x,mat y,mat ret){
	memset(ret,0x3f,sizeof(mat));
	for(ri i=0;i<maxa;++i)
		for(ri j=0;j<maxa;++j)
			for(ri k=0;k<maxa;++k)
				ckmin(ret[i][j],x[i][k]+y[k][j]);
}
inline void reset(mat x,int y){
	memset(x,0x3f,sizeof(mat));
	for(ri i=0;i<3;++i)
		for(ri j=0;j<4;++j){
			ri tmp=d[i][j];
			if(tmp>=0)ckmin(x[j][tmp],i==y?0:1);
		}
}
char s[maxn];
struct segment_tree{
	int l,r;
	mat v;
}t[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	mul(t[ls(p)].v,t[rs(p)].v,t[p].v);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		reset(t[p].v,s[l]-'a');
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void modify(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subset){
		reset(t[p].v,v);
		return;
	}
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
	push_up(p);
}
int a[maxn],m,n,t_case;
char ss[5];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	build(1,1,n);
	while(m--){
		ri pos;
		scanf("%d%s",&pos,ss);
		modify(1,pos,pos,*ss-'a');
		ri ans=INT_MAX;
		for(ri i=0;i<4;++i)ckmin(ans,t[1].v[0][i]);
		printf("%d\n",ans);
	}
	return 0;
}