#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define N 100000
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
using namespace std;
int n,m,k,ks,len,x[N+5],y[N+5],z[N+5],son[N+5][26],fail[N+5],siz[N+5],cnt,t[N+5],fs[N+5],f[N+5],dh,bg[N+5],en[N+5],nx,ny,r;ll tot,ans[N+5];
char c[N+5];vector<int> id[N+5];queue<int> q;
struct ques{int w,id,flag;}now,b[N+5<<1];vector<ques> g[N+5];
I bool cmp(ques x,ques y){return x.w<y.w;}
I void insert(int x){for(int i=1,now=0;i<=len;i++) !son[now][c[i]-'a']&&(son[now][c[i]-'a']=++cnt),now=son[now][c[i]-'a'],id[x].push_back(now);}
struct yyy{int to,z;};
struct ljb{
	int head,h[N+5];yyy f[N+5<<1];
	I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
I void bfs(){
	register int i,tot;for(i=0;i<26;i++) if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		tot=q.front();q.pop();
		for(i=0;i<26;i++) {
			if(!son[tot][i]) son[tot][i]=son[fail[tot]][i];
			else fail[son[tot][i]]=son[fail[tot]][i],q.push(son[tot][i]);
		}
	}
}
I void dfs(int x){
	yyy tmp;bg[x]=++dh;
	for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],dfs(tmp.to),siz[x]+=siz[tmp.to];en[x]=dh;
}
I void add(int x,int y){
	re int i;nx=x/ks;ny=y/ks;if(nx==ny) {for(i=x;i<=y;i++) f[i]++;return;}
	for(i=nx+1;i<ny;i++) fs[i]++;for(i=x;i<=nx*ks+ks-1;i++) f[i]++;for(i=ny*ks;i<=y;i++) f[i]++;
}
I int find(int x){return f[x]+fs[x/ks];}
I void get(ques x){for(re int i=0;i<id[x.w].size();i++) ans[x.id]+=find(bg[id[x.w][i]])*x.flag;}
I void make(int x){yyy tmp;for(int i=s.h[x];i;i=tmp.z)tmp=s.f[i],make(tmp.to),siz[x]+=siz[tmp.to];}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j,h;scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",c+1),t[i]=len=strlen(c+1),k+=t[i],insert(i);ks=sqrt(cnt);k=sqrt(k);
	for(i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]),t[z[i]]<=k&&(g[x[i]-1].push_back((ques){z[i],i,-1}),g[y[i]].push_back((ques){z[i],i,1}),0);
	bfs();for(i=1;i<=cnt;i++) s.add(fail[i],i);dfs(0);
	for(i=1;i<=n;i++){
		tot=id[i][id[i].size()-1];add(bg[tot],en[tot]);/*printf("%d\n",g[i].size());*/if(!g[i].size()) continue;
		for(j=0;j<g[i].size();j++)get(g[i][j]);
	}
	for(i=1;i<=n;i++) g[i].clear();
	for(i=1;i<=m;i++)t[z[i]]>k&&(g[z[i]].push_back((ques){x[i]-1,i,-1}),g[z[i]].push_back((ques){y[i],i,1}),0);
	for(i=1;i<=n;i++){
		for(j=0;j<g[i].size();j++) b[j]=g[i][j];sort(b,b+g[i].size(),cmp);
		for(j=0;j<g[i].size();j++) g[i][j]=b[j];
	}
	for(i=1;i<=n;i++){
		if(t[i]<=k) continue;
		memset(siz,0,sizeof(siz));tot=r=0;
		for(j=0;j<id[i].size();j++) siz[id[i][j]]=1;make(0);
		while(r<g[i].size()&&!g[i][r].w)r++;
		for(j=1;j<=n;j++){
			tot+=siz[id[j][id[j].size()-1]];
			while(r<g[i].size()&&g[i][r].w==j) now=g[i][r],ans[now.id]+=tot*now.flag,r++;
		}
	}
	for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
}