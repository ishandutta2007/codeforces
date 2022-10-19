#include<cstdio>
#include<algorithm>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define ll long long
const int N=400039;
const ll mod=1000000007;
using namespace std;
int n,m,k,x,y,z,siz[N],top[N],son[N],fa[N],fl[N],st[N],sh,lcas,now,pl[N],c[N],ch;
int flag[N],pr[N],ph,mu[N],dfn[N],dh;
ll f[N],ou[N],ans,tot[N],sum[N],pus,tots,d[N],w[N];
struct yyy{int to,z;};
struct ljb{
	int head,h[N];yyy f[2*N];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s,g;
inline void dfs1(int x,int last){
	d[x]=d[last]+1;siz[x]=1;yyy tmp;fa[x]=last;dfn[x]=++dh;
 	for(beg(x);end;go) tmp=s.f[cur],(tmp.to^last)&&(dfs1(tmp.to,x),siz[x]+=siz[tmp.to],son[x]=siz[son[x]]>siz[tmp.to]?son[x]:tmp.to);
}
inline void dfs2(int x,int last){
	top[x]=last;if(!son[x]) return;dfs2(son[x],last);yyy tmp;
	for(beg(x);end;go) tmp=s.f[cur],tmp.to^fa[x]&&tmp.to^son[x]&&(dfs2(tmp.to,tmp.to),1); 
}
inline int lca(int x,int y){while(top[x]!=top[y]) d[top[x]]>d[top[y]]?x=fa[top[x]]:y=fa[top[y]];return d[x]>d[y]?y:x;}
inline ll mpow(ll x,int y=mod-2){ll ans=1;while(y)ans=(y&1)?ans*x%mod:ans,x=x*x%mod,y>>=1;return ans;}
inline bool cmp1(int x,int y){return w[x]<w[y];}
inline bool cmp2(int x,int y){return dfn[x]<dfn[y];}
inline void dfs(int x,ll &tot){
	yyy tmp;sum[x]=0;if(fl[x])tot=(tot-2*d[x]*w[x]%mod*w[x]%mod+mod)%mod,sum[x]+=w[x],fl[x]=0;
	for(int cur=g.h[x];end;go)tmp=g.f[cur],dfs(tmp.to,tot),tot=(tot-4*sum[x]*sum[tmp.to]%mod*d[x]%mod+mod)%mod,sum[x]+=sum[tmp.to],sum[x]%=mod;g.h[x]=0;
}
int main(){
	register int i,j;
//	freopen("sm.in","r",stdin);
//	freopen("sm.out","w",stdout);
	scanf("%d",&n);mu[1]=1;ou[1]=1;
	for(i=1;i<=n;i++)scanf("%lld",&w[i]),pl[i]=i;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);dfs1(1,0);dfs2(1,1);
	for(i=2;i<=n;i++){
		if(!flag[i])pr[++ph]=i,ou[i]=i-1,mu[i]=-1;
		for(j=1;j<=ph&&pr[j]*i<=n;j++){
			flag[pr[j]*i]=1;
			if(i%pr[j]==0){ou[pr[j]*i]=ou[i]*pr[j];break;}
			ou[pr[j]*i]=ou[i]*ou[pr[j]];mu[pr[j]*i]=-mu[i];
		}
	}
	sort(pl+1,pl+n+1,cmp1);
	for(i=1;i<=n;i++) w[i]=ou[w[i]];
	for(i=1;i<=n/2;i++){
		for(pus=tots=ch=0,j=i;j<=n;j+=i) c[++ch]=pl[j],pus+=w[pl[j]],tots+=w[pl[j]]*d[pl[j]]%mod,fl[pl[j]]=1;
		tots%=mod;pus%=mod;tot[i]=2*pus%mod*tots%mod;sort(c+1,c+ch+1,cmp2);g.head=0;st[sh=1]=0;
		for(j=1;j<=ch;j++){
			now=c[j];lcas=lca(st[sh],now);while(d[lcas]<d[st[sh-1]]) g.add(st[sh-1],st[sh]),sh--;lcas=lca(now,st[sh]);
			if(lcas!=st[sh]) g.add(lcas,st[sh]),lcas==st[sh-1]?sh--:st[sh]=lcas;st[++sh]=now;
		}
		while(--sh) g.add(st[sh],st[sh+1]);dfs(0,tot[i]);//printf("%lld\n",tot[i]);
	}
	for(i=1;i<=n/2;i++) {
		for(j=1;j<=n/i;j++) f[i]+=tot[j*i]*mu[j];
		f[i]=(mod+f[i]%mod)%mod;
	}
	for(i=1;i<=n/2;i++) ans+=i*mpow(ou[i])%mod*f[i]%mod;ans%=mod;
	printf("%lld\n",ans*mpow((ll)n*(n-1)%mod)%mod);
}