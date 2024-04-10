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
const int mod=998244353;
const int maxn=(2e5)+10;
int T,n;
struct node { int to,x,y; };
vector<node> g[maxn];
int now[maxn],X[maxn];
vector<pair<int,int> > vec[maxn];
int tim;
int P[maxn],tot,prime[maxn],vis[maxn],mx[maxn];
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
void dfs(int u,int p) {
	for (node &A : g[u]) if (A.to!=p) {
		int v=A.to;
		int x=A.x,y=A.y; vector<int> V; tim++;
		X[v]=(ll)X[u]*y%mod*ksm(x,mod-2)%mod;
		for (auto [a,b] : vec[x]) {
			now[a]+=b; mx[a]=max(mx[a],now[a]);
		}
		for (auto [a,b] : vec[y]) {
			now[a]-=b; mx[a]=max(mx[a],now[a]);
		}
		dfs(v,u);
		for (auto [a,b] : vec[x]) now[a]-=b;
		for (auto [a,b] : vec[y]) now[a]+=b;
	}
}
int main() {
	for (int i=2;i<maxn;i++) {
		if (!vis[i]) prime[++tot]=i,P[i]=i;
		for (int j=1;j<=tot;j++) {
			if ((ll)i*prime[j]>=maxn) break;
			int tmp=i*prime[j];
			P[tmp]=prime[j],vis[tmp]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=2;i<maxn;i++) {
		int x=i;
		while (x>1) {
			int t=P[x],cnt=0;
			assert(t!=1&&x%t==0);
			while (x%t==0) x/=t,cnt++;
			vec[i].push_back(MP(t,cnt));
		}
	}
	read(T);
	while (T--) {
		read(n);
		int x,y,i,j;
		for (int i=1;i<=n;i++) g[i].clear(),mx[i]=now[i]=0;
		for (int I=1;I<n;I++) {
			read(i),read(j),read(x),read(y);
			int G=__gcd(x,y);
			x/=G,y/=G;
			//assert(x<=n&&y<=n);
			g[i].push_back((node){j,x,y});
			g[j].push_back((node){i,y,x});
		}
		X[1]=1;
		dfs(1,0);
		int tmp=1;
		for (int i=1;i<=n;i++) tmp=(ll)tmp*ksm(i,mx[i])%mod;//,printf("%d %d\n",i,mx[i]);
		int ans=0;
		for (int i=1;i<=n;i++) ans=(ans+X[i])%mod;//,printf("??%lld\n",(ll)X[i]*tmp%mod);
		printf("%lld\n",(ll)ans*tmp%mod);
	}
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