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
const ll INF=1e18;
const int maxn=1010;
const int mod=998244353;
int T,n,m;
ll a[maxn];
int q[maxn],hd,tl;
int in[maxn],out[maxn];
vector<int> g[maxn];
int ans[maxn][maxn];
ll r[maxn][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void add(ll &x,ll y) { x+=y; if (x>INF) x=INF; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]),g[i].clear(),in[i]=out[i]=0;
		
		for (int i=1;i<=m;i++) {
			int x,y; read(x),read(y);
			in[y]++,out[x]++;
			g[x].push_back(y);
		}
		int flag=1; for (int i=1;i<=n;i++) flag&=(a[i]==0); if (flag) { puts("0"); continue; }
		
		hd=1,tl=0;
		for (int i=1;i<=n;i++) if (!in[i]) q[++tl]=i;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) ans[i][j]=r[i][j]=0;
		while (hd<=tl) {
			int x=q[hd]; hd++;
			update(ans[x][1],a[x]);
			add(r[x][1],a[x]);
			for (int &y : g[x]) {
				in[y]--;
				for (int i=1;i<=n;i++) update(ans[y][min(i+1,n)],ans[x][i]),add(r[y][min(i+1,n)],r[x][i]);
				if (!in[y]) q[++tl]=y;
			}
		}
		int x=q[tl];
	//	for (int i=1;i<=n;i++) printf("%d ",ans[x][i]); puts("");
		
		int res=0;
		for (int i=1;i<=n;i++) {
			if (!r[x][i]) continue;
			ll R=i+r[x][i]-1;
			int len=0,bd;
			for (int j=i;j<=R&&j<=n;j++) {
				update(len,ans[x][j]);
				R+=r[x][j]; if (R>INF) R=INF;
				bd=j;
			}
			res=(len+i-1)%mod;
			i=bd;
		}
		printf("%d\n",res);
		
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