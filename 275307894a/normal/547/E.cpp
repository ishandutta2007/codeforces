#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
using namespace std;
int n,m,k,x,y,z,now,cnt,id[200039],tot[500039],g[200039],bg[200039],siz[200039],dfn;
char a[200039];
vector<int> d[200039];
struct yyy{int to,z;};
struct ljb{
	int head,h[200039];yyy f[200039];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
struct ques{int x,flag,id;}tmp;
vector<ques> sf[200039];
struct AC{int son[26],fail;}f[200039];
inline void get(int x){
	register int i;now=0;
	for(i=1;i<=k;i++)now=f[now].son[a[i]-'a']?f[now].son[a[i]-'a']:(f[now].son[a[i]-'a']=++cnt),d[x].push_back(now);id[x]=now;
}
queue<int> q;
inline void bfs(){
	register int i;
	for(i=0;i<=25;i++)if(f[0].son[i]) q.push(f[0].son[i]);
	while(!q.empty()){
		now=q.front();q.pop();
		for(i=0;i<=25;i++){
			if(f[now].son[i])f[f[now].son[i]].fail=f[f[now].fail].son[i],q.push(f[now].son[i]);
			else f[now].son[i]=f[f[now].fail].son[i];
		}
	}
}
inline void dfs(int x){
	yyy tmp;siz[x]=1;bg[x]=++dfn;
	for(beg(x);end;go)tmp=s.f[cur],dfs(tmp.to),siz[x]+=siz[tmp.to];
}
inline void gets(int x){while(x<=dfn) g[x]++,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans+=g[x],x-=x&-x;return ans;}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%s",a+1),k=strlen(a+1),get(i);bfs();
	for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),sf[x-1].push_back((ques){z,-1,i}),sf[y].push_back((ques){z,1,i});
	for(i=1;i<=cnt;i++) s.add(f[i].fail,i);dfs(0);
	for(i=1;i<=n;i++){
		for(j=0;j<d[i].size();j++) now=d[i][j],gets(bg[now]);
		for(j=0;j<sf[i].size();j++)
		tmp=sf[i][j],tot[tmp.id]+=tmp.flag*(find(bg[id[tmp.x]]+siz[id[tmp.x]]-1)-find(bg[id[tmp.x]]-1));
	}
	for(i=1;i<=m;i++) printf("%d\n",tot[i]);
}