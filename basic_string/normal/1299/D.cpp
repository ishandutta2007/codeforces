#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,E=N<<1,M=377,P=1e9+7;
struct L{
	int a[5];
	inline void set(int x){a[0]=x&1,a[1]=x>>1&3,a[2]=x>>3&7,a[3]=x>>6&15,a[4]=x>>10&31;}
	bool chk(){for(int i=4;~i;--i)if(a[i]&&!(a[i]&(1<<i)))return 0;return 1;}
	bool ins(int x){for(int i=4;~i;--i)if(x&(1<<i)){if(!a[i])return a[i]=x,1;x^=a[i];}return 0;}
	int get(){int i,j;for(i=0;i<5;++i)if(a[i])for(j=i-1;~j;--j)if(a[i]&(1<<j))a[i]^=a[j];return a[0]|a[1]<<1|a[2]<<3|a[3]<<6|a[4]<<10;}
	bool mg(L b){int i,j,x;for(i=4;~i;--i)if(x=b.a[i],x&&!ins(x))return 0;return 1;}
}a,u;
int p[33007],v[N],ct,q[M],he[N],to[E],len[E],ne[E],f[M],g[M],e[N],r[N],w[N],h[N],hh[N],tr[M][M],_,fa[N];
bool b[N],d[N],o;
void dfs(int x,int y,int f){
	h[x]=y,v[x]=++ct,fa[x]=_;
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],!v[j])dfs(j,y^len[i],x);else if(j!=f&&j!=1&&v[j]<v[x])o&=a.ins(y^len[i]^h[j]);
}
int main(){
	int n,m,c=0,i,j,k,l,t=0;
	for(i=0;i<32768;++i)if(a.set(i),a.chk())if(j=a.get(),!p[j])q[p[j]=++c]=j;
	for(i=f[1]=v[1]=1;i<=c;++i)for(j=i;j<=c;++j)if(a.set(q[i]),u.set(q[j]),a.mg(u))tr[i][j]=tr[j][i]=p[a.get()];
	for(scanf("%d%d",&n,&m);m--;)scanf("%d%d%d",&i,&j,&k),ne[++t]=he[i],to[t]=j,len[t]=k,he[i]=t,ne[++t]=he[j],to[t]=i,len[t]=k,he[j]=t;
	for(i=he[1];i;i=ne[i])b[to[i]]=1;
	for(i=he[1];i;i=ne[i])if(hh[j=to[i]]=len[i],!fa[j]){if(a.set(b[j]=0),dfs(_=j,0,o=1),!o)d[j]=1;else w[j]=a.get();}else{d[j]=1,e[fa[j]]=j;for(k=he[j];k;k=ne[k])if(to[k]==fa[j])r[fa[j]]=len[k];}
	for(i=he[1];i;i=ne[i])if(!d[j=to[i]])
	if(memcpy(g,f,1508),e[j]){for(a.set(w[j]),m=a.ins(r[j]^hh[j]^hh[e[j]])?p[a.get()]:0,k=1;k<=c;++k){if(l=tr[p[w[j]]][k],l)f[l]=(f[l]+2ll*g[k])%P;if(l=tr[m][k],l)(f[l]+=g[k])%=P;}}
	else{for(k=1;k<=c;++k)if(l=tr[p[w[j]]][k],l)(f[l]+=g[k])%=P;}
	for(k=1,l=0;k<=c;++k)(l+=f[k])%=P;
	printf("%d",l);
}