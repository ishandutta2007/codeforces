#include<cstdio>
#include<queue>
#include<cstring>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
using namespace std;
int n,m,k,x,y,z,flag[100039],bg[1000039],id[1000039],cnt,now,siz[1000039],g[1000039],dfn,tot;
char a[1000039],_s;
struct AC{int son[26],fail;}f[1000039];
inline void get(int x){
	register int i;now=0;
	for(i=1;i<=k;i++)
	now=f[now].son[a[i]-'a']?f[now].son[a[i]-'a']:(f[now].son[a[i]-'a']=++cnt);id[x]=now;
}
queue<int> q;
inline void bfs(){
	register int i; 
	for(i=0;i<=25;i++)if(f[0].son[i]) q.push(f[0].son[i]);
	while(!q.empty()){
		now=q.front();q.pop();
		for(i=0;i<=25;i++){
			if(f[now].son[i]) f[f[now].son[i]].fail=f[f[now].fail].son[i],q.push(f[now].son[i]);
			else f[now].son[i]=f[f[now].fail].son[i];
		}
	}
}
struct yyy{int to,z;};
struct ljb{
	int head,h[1000039];yyy f[1000039];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
inline void dfs(int x){
	bg[x]=++dfn;yyy tmp;siz[x]=1;
	for(beg(x);end;go)tmp=s.f[cur],dfs(tmp.to),siz[x]+=siz[tmp.to];
}
inline void get(int x,int y){while(x<=dfn) g[x]+=y,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans+=g[x],x-=x&-x;return ans;}
int main(){
	//freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)scanf("%s",a+1),k=strlen(a+1),get(i);bfs();
	for(i=1;i<=cnt;i++) s.add(f[i].fail,i);
	dfs(0);
	for(i=1;i<=n;i++) get(bg[id[i]],1),get(bg[id[i]]+siz[id[i]],-1),flag[i]=1;
	for(i=1;i<=m;i++){
		_s=getchar();
		while(_s!='?'&&_s!='+'&&_s!='-') _s=getchar();
		if(_s=='+'){
			scanf("%d",&x);
			if(!flag[x]) get(bg[id[x]],1),get(bg[id[x]]+siz[id[x]],-1),flag[x]=1;
		}
		else if(_s=='-'){
			scanf("%d",&x);
			if(flag[x])flag[x]=0,get(bg[id[x]],-1),get(bg[id[x]]+siz[id[x]],1);
		}
		else{
			scanf("%s",a+1);k=strlen(a+1);now=0;tot=0;
			for(j=1;j<=k;j++)now=f[now].son[a[j]-'a'],tot+=find(bg[now]);
 		    printf("%d\n",tot);
		}
	}
}