#include<cstdio>
#include<vector>
#define l(x) f[x].l
#define r(x) f[x].r
#define f(x) f[x].f
using namespace std;
int n,m,k,x,y,z,root[100039],lastans,cnt;
vector<int> g[100039];
struct tree{int l,r,f;}f[10000039];
inline void newnode(int &x){f[++cnt]=f[x];x=cnt;}
inline void get(int x,int y,int l,int r,int &now){
	newnode(now);f(now)+=y;
	if(l==r) return;
	int m=l+r>>1;
	if(x<=m) get(x,y,l,m,l(now));
	else get(x,y,m+1,r,r(now));
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f(now);
	int m=l+r>>1,fs=0;
	if(x<=m&&l(now)) fs+=find(x,y,l,m,l(now));
	if(y>m&&r(now)) fs+=find(x,y,m+1,r,r(now));
	return fs;
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
	register int i;
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&x);root[i]=root[i-1];
		g[x].push_back(i);
		get(i,1,1,n,root[i]);
		if(g[x].size()>k) get(g[x][g[x].size()-k-1],-1,1,n,root[i]);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		x=(lastans+x)%n+1;y=(lastans+y)%n+1;
		if(x>y) swap(x,y);
		printf("%d\n",lastans=find(x,y,1,n,root[y]));
	}
}