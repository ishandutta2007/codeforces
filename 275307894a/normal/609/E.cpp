#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,fa[200039][39],g[200039][39],f[200039],pus,un,wn,d[200039],flag[200039],lg[200039];
long long tot;
struct ques{int x,y,z,num;}sf[200039];
inline bool cmp1(ques x,ques y){return x.z<y.z;}
inline bool cmp2(ques x,ques y){return x.num<y.num;}
struct yyy{int to,w,z;};
struct ljb{
	int head,h[200039];
	yyy f[400039];
	inline void add(int x,int y,int z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void dfs(int x,int last){
	yyy tmp;register int i;
	fa[x][0]=last;d[x]=d[last]+1;
	for(i=1;i<=lg[d[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1],g[x][i]=max(g[x][i-1],g[fa[x][i-1]][i-1]);
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last){
			g[tmp.to][0]=tmp.w;
			dfs(tmp.to,x);
		}
	}
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int find(int x,int y){
	int ans=0;
	if(d[x]<d[y]) swap(x,y);
	while(d[x]!=d[y]) ans=max(ans,g[x][lg[d[x]-d[y]]-1]),x=fa[x][lg[d[x]-d[y]]-1];
	if(x==y) return ans;
	for(int i=lg[d[x]];i>=0;i--) if(fa[x][i]!=fa[y][i]) ans=max(ans,max(g[x][i],g[y][i])),x=fa[x][i],y=fa[y][i];
	return max(ans,max(g[x][0],g[y][0]));
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d%d",&sf[i].x,&sf[i].y,&sf[i].z),sf[i].num=i;
	sort(sf+1,sf+m+1,cmp1);
	for(i=1;i<=m;i++){
		un=find(sf[i].x);wn=find(sf[i].y);
		if(un!=wn){
			f[un]=wn;flag[sf[i].num]=1;
			pus++;
			tot+=sf[i].z;
			s.add(sf[i].x,sf[i].y,sf[i].z);s.add(sf[i].y,sf[i].x,sf[i].z);
			if(pus==n-1) break;
		}
	}
	sort(sf+1,sf+m+1,cmp2);
	dfs(1,0);
	for(i=1;i<=m;i++){
		if(flag[i]) printf("%lld\n",tot);
		else printf("%lld\n",tot-find(sf[i].x,sf[i].y)+sf[i].z);
	}
}