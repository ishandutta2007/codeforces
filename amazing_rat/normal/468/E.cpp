// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
typedef vector<int> poly;
const int mod=(1e9)+7;
int n,k,t1,t2,jc[100010];
map<int,int> dx,dy;
struct node { int x,y,z; } now[60];
vector<node> H;
vector<pair<int,int> > g[120];
int dep[120];
void add_edge(int x,int y,int z) { g[x].push_back(MP(y,z)); g[y].push_back(MP(x,z)); }
bool vis[120];
vector<int> L,R;
vector<pair<int,int> > tr[120];
int V,E;
void dfs(int u) {
	if (vis[u]) return; vis[u]=1;
	if (u<=t1) L.push_back(u); else R.push_back(u); V++;
	E+=(int)g[u].size();
	for (pair<int,int> A : g[u]) {
		if (vis[A.first]) continue;
		dep[A.first]=dep[u]+1;
		tr[u].push_back(A);
		dfs(A.first);
	}
}
poly res,all;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
poly operator * (poly t1,poly t2) {
	poly res; int n=(int)t1.size()-1,m=(int)t2.size()-1; res.resize(n+m+1,0);
	for (int i=0;i<=n;i++) if (t1[i])
	for (int j=0;j<=m;j++) if (t2[j])
		update(res[i+j],(ll)t1[i]*t2[j]%mod);
	return res;
}
poly operator + (poly t1,poly t2) {
	while ((int)t1.size()<(int)t2.size()) t1.push_back(0);
	for (int i=0;i<t2.size();i++) update(t1[i],t2[i]);
	return t1;
}
poly operator - (poly t1,poly t2) {
	for (int i=0;i<t2.size();i++) update(t1[i],mod-t2[i]);
	return t1;
}
poly operator * (poly t1,int t2) {
	for (int i=0;i<t1.size();i++) t1[i]=(ll)t1[i]*t2%mod;
	return t1;
}
int bit[1<<20],dp[1<<20],Dy[120];
int sz;
poly f[120][2];
bool ban[120];
poly T[120];
void dfs_dp(int rt) {
	f[rt][0]={1};
	for (pair<int,int> A : tr[rt]) {
		int v=A.first;
		//printf("HI %d %d\n",rt,v);
		dfs_dp(v); T[v]=f[v][0]+f[v][1];
		//if (ban[5]&&rt==2&&v==5) printf("HI  %d %d\n",v,T[v][0]);
		f[rt][0]=f[rt][0]*T[v];
	}
	//for (int i=0;i<f[rt][0].size();i++) if (f[rt][0][i]) printf("rt=%d,op=0,i=%d,f=%d\n",rt,i,f[rt][0][i]);
	if (ban[rt]) { f[rt][1]={0}; return; }
	f[rt][1]={0};
	poly pre[120],suf[120];
	//printf("OK %d\n",rt);
	for (int i=0;i<tr[rt].size();i++) {
		if (i) pre[i]=pre[i-1]*T[tr[rt][i].first];
		else pre[i]=T[tr[rt][i].first];
	}
	for (int i=(int)tr[rt].size()-1;i>=0;i--) {
		if (i!=(int)tr[rt].size()-1) suf[i]=suf[i+1]*T[tr[rt][i].first];
		else suf[i]=T[tr[rt][i].first];
	}
	//printf("OK %d\n",rt);
	int i=0;
	for (pair<int,int> A : tr[rt]) {
		int v=A.first; if (ban[v]) { i++; continue; }
		poly tmp=(f[v][0]*A.second);
		//if (ban[5]&&rt==2) printf("HI %d %d %d %d\n",v,tmp[0],tmp[1],i!=(int)tr[rt].size()-1);
		if (i) tmp=tmp*pre[i-1];
		if (i!=(int)tr[rt].size()-1) tmp=tmp*suf[i+1];
	//	if (rt==1) printf("! v=%d %d\n",v,tmp[1]);
		f[rt][1]=f[rt][1]+tmp; i++;
		//if (ban[5]&&rt==2) printf("HI %d %d %d\n",v,tmp[0],tmp[1]);
	}
	f[rt][1]=f[rt][1]*(poly){0,1};
	//for (int i=0;i<f[rt][1].size();i++) if (f[rt][1][i]) printf("rt=%d,op=1,i=%d,f=%d\n",rt,i,f[rt][1][i]);
	return;
	f[rt][1].push_back(0);
	for (int i=(int)f[rt][1].size()-2;i>=0;i--) f[rt][1][i+1]=f[rt][1][i];
	f[rt][1][0]=0;
	//printf("OK %d\n",rt);
	//for (int i=0;i<f[rt][1].size();i++) printf("rt=%d,op=1,i=%d,f=%d\n",rt,i,f[rt][1][i]);
}
void solve1(int rt) {
	H.clear();
	for (int x : L) for (pair<int,int> A : g[x]) {
		int y=A.first; if (dep[x]>dep[y]+1) H.push_back((node){x,y,A.second});
	}
	for (int x : R) for (pair<int,int> A : g[x]) {
		int y=A.first; if (dep[x]>dep[y]+1) H.push_back((node){x,y,A.second});
	}
	int SZ=(int)H.size(),bit=0;
	//printf("sz=%d,rt=%d, %d %d, %d\n",sz,rt,(int)L.size(),(int)R.size(),SZ);
	//printf("? %d %d\n",E,V);
//	for (node A : H) printf("(%d,%d,%d)\n",A.x,A.y,A.z);
	for (int t=0;t<(1<<SZ);t++) {
		for (int x : L) ban[x]=0; for (int x : R) ban[x]=0;
		int flag=1,x,y,tmp=1; bit=0;
	//printf("OK2 %d\n",rt);
		for (int i=0;i<SZ;i++) if (t&(1<<i)) {
			x=H[i].x,y=H[i].y; bit++;
			if (ban[x]||ban[y]) { flag=0; break; }
			ban[x]=ban[y]=1; tmp=(ll)tmp*H[i].z%mod;
		}
		if (!flag) continue;
		dfs_dp(rt);
	//printf("OK %d, %d %d\n",rt,(int)f[rt][0].size(),(int)f[rt][1].size());
	//for (int i=0;i<f[rt][0].size();i++) printf("%d ",f[rt][0][i]); puts("");
		for (int i=0;i<f[rt][0].size();i++) if (f[rt][0][i])
			update(res[i+bit],(ll)tmp*f[rt][0][i]%mod);
	//printf("OK %d\n",rt);
		for (int i=0;i<f[rt][1].size();i++) if (f[rt][1][i])
			update(res[i+bit],(ll)tmp*f[rt][1][i]%mod);
	}
}
void solve2() {
	//printf("sz=%d\n",sz);
	for (int t=0;t<(1<<sz);t++) {
		dp[t]=0; if (t) bit[t]=bit[t-(t&(-t))]+1;
	}
	dp[0]=1;
	for (int i=0;i<L.size();i++) Dy[L[i]]=i;
	for (int x : R) {
		for (int t=(1<<sz)-1;t>=0;t--) if (dp[t]) {
			for (pair<int,int> A : g[x]) {
				int y=Dy[A.first]; if (t&(1<<y)) continue;
				update(dp[t|(1<<y)],(ll)A.second*dp[t]%mod);
			}
		}
	}
	for (int t=0;t<(1<<sz);t++) update(res[bit[t]],dp[t]);
}
int main() {
//	freopen("matrix.in","r",stdin); freopen("matrix.out","w",stdout);
	read(n),read(k); int x,y,z;
	for (int i=1;i<=k;i++) {
		read(x),read(y),read(z); z--;
		if (!dx[x]) dx[x]=++t1;
		x=dx[x];
		if (!dy[y]) dy[y]=++t2;
		y=dy[y];
		now[i]=(node){x,y,z};
	}
	for (int i=1;i<=k;i++) {
		add_edge(now[i].x,now[i].y+t1,now[i].z);
	}
	jc[0]=jc[1]=1; for (int i=2;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	all={1};
	for (int i=1;i<=t1;i++) if (!vis[i]) {
		V=E=0; L.clear(),R.clear(); dfs(i); E/=2;
		if ((int)L.size()>(int)R.size()) swap(L,R);
		sz=(int)L.size(); res=poly(sz+1,0);
		if (E<=V*3/2) solve1(i);
		else solve2();
		all=all*res;
		//for (int i=0;i<=sz;i++) printf("%d ",res[i]); puts("");
	}
	int ans=0;
	for (int i=0;i<all.size();i++) update(ans,(ll)all[i]*jc[n-i]%mod);
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/