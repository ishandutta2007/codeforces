#include<cstdio>
#include<cstring>
#include<algorithm>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define l(x) x<<1
#define r(x) x<<1|1
#define N 1000039
#define ll long long
#define ui unsigned int
#define mod 23333333333333333
using namespace std;
int n,m,k,qs,b[N],st[N],sh,fa[N],top[N],d[N],son[N],siz[N],tot[N],pl[N],dh,dfn[N],now,lcas,si[N];char a[N];ll ans;
struct yyy {int to,z;};
struct ljb{
	int head,h[N];yyy f[N];
	I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s,q;
struct SAM{
	 int fa[N],len[N],son[N][26],cnt=1,last=1,p,now,pus,cur;
	 I void insert(int x){
		p=last;now=last=++cnt;len[now]=len[p]+1;siz[now]++;
		while(p&&!son[p][x]) son[p][x]=now,p=fa[p];
		if(!p) return (void)(fa[now]=1);
		cur=son[p][x];if(len[cur]==len[p]+1) fa[now]=cur;
		else{
			fa[pus=++cnt]=fa[cur];len[pus]=len[p]+1;memcpy(son[pus],son[cur],sizeof(son[pus]));fa[cur]=fa[now]=pus;
			while(p&&son[p][x]==cur) son[p][x]=pus,p=fa[p];
		}
	}
}g;
I void dfs1(int x,int last){
	fa[x]=last;siz[x]=1;d[x]=d[last]+1;yyy tmp;dfn[x]=++dh;
	for(beg(x);end;go) tmp=s.f[cur],dfs1(tmp.to,x),siz[x]+=siz[tmp.to],son[x]=siz[son[x]]>siz[tmp.to]?son[x]:tmp.to;
}
I void dfs2(int x,int last){
	top[x]=last;if(!son[x]) return;dfs2(son[x],last);yyy tmp;
	for(beg(x);end;go) tmp=s.f[cur],tmp.to^son[x]&&(dfs2(tmp.to,tmp.to),0);
}
I int lca(int x,int y){while(top[x]^top[y]) d[top[x]]>d[top[y]]?(x=fa[top[x]]):(y=fa[top[y]]);return d[x]<d[y]?x:y;}
I bool cmp(int x,int y){return dfn[x]<dfn[y];}
I void dfs(int x){yyy tmp;for(int cur=q.h[x];end;go) tmp=q.f[cur],dfs(tmp.to),si[x]+=si[tmp.to],tot[x]+=tot[tmp.to],ans-=(ll)si[tmp.to]*tot[tmp.to]*g.len[x],si[tmp.to]=tot[tmp.to]=0;ans+=(ll)si[x]*tot[x]*g.len[x];q.h[x]=0;}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	register int i;scanf("%d%d",&n,&m);scanf("%s",a+1);
	for(i=n;i;i--) g.insert(a[i]-'a'),pl[i]=g.last;
	for(i=2;i<=g.cnt;i++) s.add(g.fa[i],i);dfs1(1,0);dfs2(1,1);
	while(m--){
		scanf("%d%d",&k,&qs);for(i=1;i<=k;i++) scanf("%d",&b[i]),b[i]=pl[b[i]],si[b[i]]++;for(i=1;i<=qs;i++) scanf("%d",&b[i+k]),b[i+k]=pl[b[i+k]],tot[b[i+k]]++;
		sort(b+1,b+k+qs+1,cmp);st[sh=1]=1;q.head=ans=0;
		for(i=1;i<=k+qs;i++){
			now=b[i];if(now==b[i-1])continue;lcas=lca(now,st[sh]);while(sh&&d[lcas]<d[st[sh-1]]) q.add(st[sh-1],st[sh]),sh--; 
			if(lcas^st[sh]) q.add(lcas,st[sh]),lcas^st[sh-1]?(st[sh]=lcas):(sh--);st[++sh]=now;
		}
		while(--sh) q.add(st[sh],st[sh+1]);dfs(1);printf("%lld\n",ans%mod);
	}
}