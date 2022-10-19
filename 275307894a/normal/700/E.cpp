#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define l(x) g[x].l
#define r(x) g[x].r
using namespace std;
int n,m,k,x,y,z,tot,pus,p,cur,now,cnt=1,last=1,pos[400039],ans=1,root[400039],pl[400039],fs[400039],id[400039],dp[400039],fa;
char s[200039];
struct SAM{int son[26],fa,len;}f[400039];
inline void insert(int x,int id){
	p=last;last=now=++cnt;f[now].len=f[p].len+1;pos[now]=id;
	while(p&&!f[p].son[x]) f[p].son[x]=now,p=f[p].fa;
	if(!p)return (void)(f[now].fa=1);
	cur=f[p].son[x];if(f[p].len+1==f[cur].len)return (void)(f[now].fa=cur);
	f[pus=++cnt]=f[cur];f[pus].len=f[p].len+1;f[cur].fa=f[now].fa=cnt;pos[pus]=pos[cur];
	while(p&&f[p].son[x]==cur) f[p].son[x]=pus,p=f[p].fa;
}
struct tree{int l,r;}g[10000039];
inline int merge(int x,int y){
	if(!x||!y) return x|y;int now=++tot;
	l(now)=merge(l(x),l(y));r(now)=merge(r(x),r(y));return now;
}
inline void get(int x,int &now,int l=1,int r=n){
	if(!now)now=++tot;if(l==r) return;
	int m=l+r>>1;(x<=m)?get(x,l(now),l,m):get(x,r(now),m+1,r);
}
inline int find(int x,int y,int now,int l=1,int r=n){
	if(!now) return 0;if(x<=l&&r<=y) return 1;int m=l+r>>1;
	return (x<=m&&find(x,y,l(now),l,m))||(y>m&&find(x,y,r(now),m+1,r));
}
int main(){
	register int i,j;
//	freopen("level.in","r",stdin);
//	freopen("level.out","w",stdout);
	scanf("%d",&n);scanf("%s",s+1);
	for(i=1;i<=n;i++) 
	insert(s[i]-'a',i),get(i,root[last]);
	for(i=1;i<=cnt;i++) fs[f[i].len]++;
	for(i=1;i<=cnt;i++) fs[i]+=fs[i-1];
	for(i=cnt;i;i--) pl[fs[f[i].len]--]=i;
	for(i=cnt;i>=2;i--) root[f[pl[i]].fa]=merge(root[f[pl[i]].fa],root[pl[i]]); 
	for(i=2;i<=cnt;i++){
		now=pl[i];fa=f[now].fa;
		if(!(fa^1)) {dp[now]=1;id[now]=now;continue;}
		dp[now]=dp[id[fa]]+find(pos[now]-f[now].len+f[id[fa]].len,pos[now]-1,root[id[fa]]);
		if(dp[now]^dp[id[fa]])id[now]=now;
		else id[now]=id[fa];
		ans=max(ans,dp[now]);
	} 
	printf("%d\n",ans);
}