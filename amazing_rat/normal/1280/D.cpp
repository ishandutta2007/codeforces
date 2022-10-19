#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=(1e9);
int T,n,m,sz[3010],tmp;
ll d[3010];
int tot,head[3010],nxt[6010],to[6010];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
struct node {
	int x; ll y;
} dp[3010][3010],N[3010];
void update(node &a,node b) {
	if (b.x>a.x) a=b;
	else if (b.x==a.x&&b.y>a.y) a=b;
}
void dfs(int u,int p) {
	sz[u]=1;
	dp[u][0]=(node){0,d[u]};
	dp[u][1]=(node){-INF,0};
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
		for (int a=0;a<=sz[u]+sz[v];a++)
			N[a]=(node){-INF,0};
		for (int a=0;a<=sz[u];a++)
		for (int b=0;b<=sz[v];b++) {
			tmp=dp[u][a].x+dp[v][b].x;
			update(N[a+b],(node){tmp,dp[u][a].y+dp[v][b].y});
			if (dp[v][b].y>0) tmp++;
			update(N[a+b+1],(node){tmp,dp[u][a].y});
		}
		sz[u]+=sz[v];
		for (int a=0;a<=sz[u];a++) dp[u][a]=N[a];
	}
	//for (int a=0;a<=sz[u];a++) printf("%d %d %d %lld\n",u,a,dp[u][a].x,dp[u][a].y);
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y;
	read(T);
	while (T--) {
		read(n);
		read(m);
		tot=0;
		for (int i=1;i<=n;i++)
			head[i]=d[i]=0;
		for (int i=1;i<=n;i++) read(x),d[i]-=x;
		for (int i=1;i<=n;i++) read(x),d[i]+=x;
		//for (int i=1;i<=n;i++) printf("%lld ",d[i]); printf("\n");
		for (int i=1;i<n;i++) {
			read(x); read(y);
			add(x,y); add(y,x);
		}
		dfs(1,0);
		tmp=dp[1][m-1].x;
		if (dp[1][m-1].y>0) tmp++;
		printf("%d\n",tmp);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/