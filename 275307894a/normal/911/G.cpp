#include<cstdio>
#include<cstring>
#define l(x) f[x].l
#define r(x) f[x].r
#define f(x) f[x].f
#define iv inline void 
using namespace std;
int n,m,k,x,y,z,ans[200039],root[139],l,r,flag;
int st[10000039],sh,cnt,root1,root2,root3;
struct tree{int l,r,f;}f[40000039];
inline int newnode(){return sh?st[sh--]:++cnt;}
iv clear(int x){l(x)=r(x)=f(x)=0;}
iv swap(int &x,int &y){x^=y^=x^=y;}
iv up(int now){f(now)=f(l(now))+f(r(now));}
iv split(int x,int &y,int z,int l,int r){
	if(!x) return;
	y=newnode();int m=l+r>>1;
	if(z>m) split(r(x),r(y),z,m+1,r);
	else{
	    swap(r(x),r(y));
	    if(z<m) split(l(x),l(y),z,l,m);
	}
	if(l!=r)up(x),up(y);
}
inline int merge(int x,int y,int l,int r){
	if(!x||!y) return x|y;
	if(l==r){f(y)+=f(x);st[++sh]=x;clear(x);return y;}
	int m=l+r>>1;
	l(y)=merge(l(x),l(y),l,m);r(y)=merge(r(x),r(y),m+1,r);
	st[++sh]=x;clear(x);return up(y),y;
}
iv dfs(int z,int l,int r,int now){
	if(!now||!f(now)) return;
	if(l==r){ans[l]=z;return;}
	int m=l+r>>1;
	dfs(z,l,m,l(now));dfs(z,m+1,r,r(now));
}
iv get(int x,int l,int r,int &now){
	if(!now) now=newnode();f(now)++;
	if(l==r) return;
	int m=l+r>>1;
	if(x<=m) get(x,l,m,l(now));
	else get(x,m+1,r,r(now));
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;memset(ans,-1,sizeof(ans));
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&x),get(i,0,n,root[x]);
	scanf("%d",&m);
	while(m--){//flag++;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		if(x==y) continue;root1=root2=0;
		split(root[x],root1,l-1,0,n);
		split(root1,root2,r,0,n);
		//dfs(x,0,n,root1);putchar('\n');
		root[x]=merge(root2,root[x],0,n);
		root[y]=merge(root1,root[y],0,n);
		//dfs(y,0,n,root[y]);putchar('\n');
	}
	for(i=1;i<=100;i++) dfs(i,0,n,root[i]);
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
}