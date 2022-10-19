#include<cstdio>
using namespace std;
int n,m,k,x,y,z,fa[200039][39],lg[200039],f[200039],d[200039],a[200039],lcas,now;
long long q[200039];
struct yyy{int to,w,z;};
struct ljb{
	int head,h[200039];
	yyy f[200039];
	inline void add(int x,int y,int z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	register int i;yyy tmp;
	fa[x][0]=last;d[x]=d[last]+1;
	for(i=1;i<=lg[d[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];q[tmp.to]=q[x]+tmp.w;
		dfs(tmp.to,x);
	}
}
inline int lca(int x,int y){
	register int i,j=x;
	for(i=lg[d[x]];i>=0;i--)if(y>=q[j]-q[fa[x][i]]) x=fa[x][i];
	return x;
}
inline void dfss(int x,int last){
	yyy tmp;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		dfss(tmp.to,x);
		f[x]+=f[tmp.to];
	}
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		s.add(x,i,y);
	} 
	dfs(1,0);
	for(i=1;i<=n;i++){
		lcas=lca(i,a[i]);
	//	printf("%d %d\n",i,lcas);
		f[fa[i][0]]++;f[fa[lcas][0]]--;
	}
	dfss(1,0);
	for(i=1;i<=n;i++) printf("%d ",f[i]);
}