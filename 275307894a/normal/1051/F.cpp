#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[100039],cnt,un,wn,tot,id[100039],flag[139],head,now,pus,fl[100039],lcas;
int d[100039],siz[100039],son[100039],top[100039],fa[100039];
long long de[100039],dis[49][100039],ans;
struct yyy{int to,w,z;}tmp;
struct ljb{
	int head,h[100039];yyy f[200039];
	inline void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]},h[x]=head;}
}s,g;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void dfs1(int x,int last){
	fa[x]=last;d[x]=d[last]+1,siz[x]=1;yyy tmp;
	for(beg(x);end;go){
		tmp=s.f[cur];
		if(tmp.to^last)de[tmp.to]=de[x]+tmp.w,dfs1(tmp.to,x),siz[x]+=siz[tmp.to],son[x]=siz[son[x]]>siz[tmp.to]?son[x]:tmp.to;
	}
}
inline void dfs2(int x,int last){
	top[x]=last;if(!son[x]) return;dfs2(son[x],last);yyy tmp;
	for(beg(x);end;go){
		tmp=s.f[cur];
		if((tmp.to^fa[x])&&(tmp.to^son[x])) dfs2(tmp.to,tmp.to);
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]) d[top[x]]>d[top[y]]?(x=fa[top[x]]):(y=fa[top[y]]);
	return d[x]>d[y]?y:x;
}
struct ques{
	int to;long long w;
	bool operator <(const ques &x)const{return w>x.w;}
}tmps;
priority_queue<ques> q;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		un=find(x);wn=find(y);
		if(un!=wn&&cnt<n-1){
			f[un]=wn;s.add(x,y,z);s.add(y,x,z);cnt++;
		}
		else{
			id[x]=id[x]?id[x]:(id[x]=++tot,flag[tot]=x);
			id[y]=id[y]?id[y]:(id[y]=++tot,flag[tot]=y);
		}
		g.add(x,y,z);g.add(y,x,z);
	}
	dfs1(1,0);dfs2(1,1);s=g;
	memset(dis,0x3f,sizeof(dis));
	for(i=1;i<=tot;i++){
		pus=flag[i];dis[i][pus]=0;q.push((ques){pus,0});
		while(!q.empty()){
			tmps=q.top();q.pop();fl[tmps.to]=0;
			for(beg(tmps.to);end;go){
				tmp=s.f[cur];
				if(dis[i][tmp.to]>dis[i][tmps.to]+tmp.w){
					dis[i][tmp.to]=dis[i][tmps.to]+tmp.w;
					if(!fl[tmp.to]) q.push((ques){tmp.to,dis[i][tmp.to]}),fl[tmp.to]=1;
				}
			}
		}
	}
	scanf("%d",&k);while(k--){
		scanf("%d%d",&x,&y);ans=1e18;
		lcas=lca(x,y);ans=min(ans,de[x]+de[y]-2*de[lcas]);
		for(i=1;i<=tot;i++)ans=min(ans,dis[i][y]+dis[i][x]);
		printf("%lld\n",ans);
	}
}