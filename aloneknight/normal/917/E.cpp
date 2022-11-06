#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=200005;
int n,m,Q,len[N],ans[N];char s[N],*str[N];
int cc=1,S,rt,tt,hd[N],vis[N],sz[N],mx[N];
int nn,fr[N],tg[N],lu[N],lv[N];
vi Qu[N],Qv[N],Qt[N],Qc[N];
struct E{int v,nxt,w;}e[N];
inline void addedge(int u,int v,char w){e[++cc]=(E){v,hd[u],w-'a'};hd[u]=cc;e[++cc]=(E){u,hd[v],w-'a'};hd[v]=cc;} 
struct qr{int u,v,s;}q[N];
struct AC
{
	int n,nn,tt,ch[N][26],fa[N],pos[N],dl[N],dr[N],c[N];vi e[N];
	//reset
	inline void init()
	{
		rep(i,0,n)
		{
			memset(ch[i],0,sizeof(ch[i]));
			fa[i]=dl[i]=dr[i]=0;e[i].clear();
		}
		rep(i,1,nn)pos[i]=0;n=tt=nn=0;
	}
	//build trie
	inline void ins(char*s)
	{
		int l=strlen(s+1),x=0,c;
		for(int i=1;i<=l;i++,x=ch[x][c])if(!ch[x][c=s[i]-'a'])ch[x][c]=++n;
		pos[++nn]=x;
	}
	//build AC automaton and fail tree
	void dfs(int x){dl[x]=++tt;for(int y:e[x])dfs(y);dr[x]=tt;}
	void build()
	{
		queue<int>q;
		rep0(i,0,26)if(ch[0][i])q.push(ch[0][i]);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			rep0(i,0,26)if(ch[x][i])fa[ch[x][i]]=ch[fa[x]][i],q.push(ch[x][i]);else ch[x][i]=ch[fa[x]][i];
		}
		rep(i,1,n)e[fa[i]].pb(i);dfs(0);
	}
	//BIT built on dfs order of fail tree
	inline void upd(int x,int v){for(;x<=n+1;x+=x&-x)c[x]+=v;}
	inline int qry(int x){int s=0;for(;x;x-=x&-x)s+=c[x];return s;}
	inline void upd1(int x,int v){upd(dl[x],v);}
	inline int qry1(int x){x=pos[x];return qry(dr[x])-qry(dl[x]-1);}
	inline void upd2(int x,int v){upd(dl[x],v);upd(dr[x]+1,-v);}
	inline int qry2(int x){return qry(dl[x]);}
}A1,A2,K1,K2;
struct SAM
{
	int n=1,lst=1,nn,tt,ch[N][26],fa[N],len[N],dl[N],dr[N],pos[N];vi e[N],T[N*4];
	//build SAM
	inline void extend(int c)
	{
		int p=lst;
		if(ch[p][c])
		{
			int q=ch[p][c];if(len[q]==len[p]+1){lst=q;return;}
			int nq=++n;len[nq]=len[p]+1;lst=nq;
			fa[nq]=fa[q];fa[q]=nq;memcpy(ch[nq],ch[q],sizeof(ch[q]));
			for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;return;
		}
		int np=lst=++n;len[np]=len[p]+1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];if(len[q]==len[p]+1){fa[np]=q;return;}
		int nq=++n;len[nq]=len[p]+1;fa[nq]=fa[q];
		fa[q]=fa[np]=nq;memcpy(ch[nq],ch[q],sizeof(ch[q]));
		for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	inline void ins(char*s)
	{
		int l=strlen(s+1);lst=1;
		rep(i,1,l)extend(s[i]-'a');
		pos[++nn]=lst;
	}
	//build parent tree
	void dfs(int x){dl[x]=++tt;for(int y:e[x])dfs(y);dr[x]=tt;} 
	void build(){rep(i,2,n)e[fa[i]].pb(i);dfs(1);}
	//segment tree
	void Upd(int x,int l,int r,int tl,int tr,int v)
	{
		if(tl<=l&&r<=tr){if(v>=0)T[x].pb(v);else T[x].pop_back();return;}
		int m=l+r>>1;if(tl<=m)Upd(ls,tl,tr,v);if(tr>m)Upd(rs,tl,tr,v);
	}
	int Qry(int x,int l,int r,int p)
	{
		if(l==r)return T[x].empty()?0:T[x].back();int m=l+r>>1;
		return max(T[x].empty()?0:T[x].back(),p<=m?Qry(ls,p):Qry(rs,p));
	}
	void upd(int x,int v){if(x)Upd(1,1,n,dl[x],dr[x],v);}
	int qry(int x){x=pos[x];return Qry(1,1,n,dl[x]);}
}S1,S2;
//get size and centroid
void gtrt(int x,int p)
{
	sz[x]=1;mx[x]=0;
	for(int i=hd[x],y;i;i=e[i].nxt)if(!vis[y=e[i].v]&&y!=p){gtrt(y,x);sz[x]+=sz[y];mx[x]=max(mx[x],sz[y]);}
	mx[x]=max(mx[x],S-sz[x]);if(mx[x]<mx[rt])rt=x;
}
//get the part of each vertex
void dfs1(int x,int p,int o)
{
	fr[x]=o;tg[x]=tt;sz[x]=1;
	for(int i=hd[x],y;i;i=e[i].nxt)if(!vis[y=e[i].v]&&y!=p)dfs1(y,x,o),sz[x]+=sz[y];
}
void dfs2(int x,int p,int a1,int a2,int s1,int s2,int d)
{
	A1.upd1(a1,1);A2.upd1(a2,1);S1.upd(s1,d);S2.upd(s2,d);
	for(int i:Qu[x])if(tg[q[i].u]==tg[q[i].v]&&fr[q[i].u]!=fr[q[i].v]){ans[i]+=A2.qry1(q[i].s);lu[i]=S2.qry(q[i].s);}
	for(int i:Qv[x])if(tg[q[i].u]==tg[q[i].v]&&fr[q[i].u]!=fr[q[i].v]){ans[i]+=A1.qry1(q[i].s);lv[i]=S1.qry(q[i].s);}
	for(int i=hd[x],y;i;i=e[i].nxt)if(!vis[y=e[i].v]&&y!=p){int w=e[i].w;dfs2(y,x,A1.ch[a1][w],A2.ch[a2][w],S1.ch[s1][w],S2.ch[s2][w],d+1);}
	A1.upd1(a1,-1);A2.upd1(a2,-1);S1.upd(s1,-1);S2.upd(s2,-1);
}
void sol(int x)
{
	rt=0;gtrt(x,0);x=rt;vis[x]=1;fr[x]=x;tg[x]=++tt;
	for(int i=hd[x],y;i;i=e[i].nxt)if(!vis[y=e[i].v])dfs1(y,x,y);
	dfs2(x,0,0,0,1,1,0);
	for(int i=hd[x],y;i;i=e[i].nxt)if(!vis[y=e[i].v]){S=sz[y];sol(y);}
}
//K1,K2 border tree of kmp
void calc(int x)
{
	if(x&&x<nn)K2.upd2(nn-x,1);
	for(int i:Qc[x])ans[i]+=K2.qry2(lv[i]);
	for(int y:K1.e[x])calc(y);
	if(x&&x<nn)K2.upd2(nn-x,-1);
}
int main()
{
	n=rd();m=rd();Q=rd();
	rep(i,1,n-1){int u=rd(),v=rd();char w[5];scanf("%s",w);addedge(u,v,w[0]);}
	rep(i,1,m)
	{
		scanf("%s",s+1);len[i]=strlen(s+1);
		A1.ins(s);S1.ins(s);reverse(s+1,s+len[i]+1);
		A2.ins(s);S2.ins(s);reverse(s+1,s+len[i]+1);
		str[i]=new char[len[i]+10];
		rep(j,1,len[i])str[i][j]=s[j];str[i][len[i]+1]=0;
	}
	A1.build();A2.build();S1.build();S2.build();
	rep(i,1,Q){q[i]=(qr){rd(),rd(),rd()};Qu[q[i].u].pb(i);Qv[q[i].v].pb(i);}
	mx[0]=n;S=n;sol(1);rep(i,1,Q)Qt[q[i].s].pb(i);
	rep(i,1,m)
	{
		K1.init();K1.ins(str[i]);reverse(str[i]+1,str[i]+len[i]+1);K1.build();
		K2.init();K2.ins(str[i]);reverse(str[i]+1,str[i]+len[i]+1);K2.build();
		nn=len[i];for(int t:Qt[i])Qc[lu[t]].pb(t);
		calc(0);rep(j,0,nn)Qc[j].clear();
	}
	rep(i,1,Q)printf("%d\n",ans[i]);return 0;
}