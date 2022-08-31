#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
vector<PII> e[N];
int cnt[10],f[N],lev[10];;
int n,m,u,v,x[N],y[N],fq[N],lab[N],sm[N],ord[N];
char s[N];

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

void dfs(int u,int f,int d) {
	cnt[s[u]-'X']+=d;
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u,-d);
	}
}
void dfs2(int u,int f) {
	fq[u]=lev[s[u]-'X'];
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs2(v,u);
		lab[p.se]=fq[v];
		fq[u]-=fq[v];
	}
//	printf("%d %d\n",u,fq[u]);
}

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	rep(i,0,m) {
		scanf("%d%d",x+i,y+i);
	}
	while (1) {
		rep(i,0,n) f[i]=i,e[i].clear();
		rep(i,0,m) ord[i]=i,lab[i]=0;
		random_shuffle(ord,ord+m);
		rep(i,0,m) {
			int u=x[ord[i]],v=y[ord[i]];
			if (find(u)!=find(v)) {
				e[u].pb(mp(v,ord[i])),e[v].pb(mp(u,ord[i]));
				f[find(u)]=find(v);
			}
		}
		rep(i,0,3) cnt[i]=0;
		int rt=rnd(n);
		dfs(rt,-1,1);
		//rep(i,0,3) printf("%d ",cnt[i]); puts("");
		rep(p1,0,3) rep(p2,0,3) if (p1!=p2) {
			int p3=3-p1-p2;
			if ((p1*cnt[0]+p2*cnt[1]+p3*cnt[2])%3==0) {
				lev[0]=p1; lev[1]=p2; lev[2]=p3;
//				printf("succ %d %d %d\n",lev[0],lev[1],lev[2]);
				goto suc;
			}
		}
		if (rnd(2)) {
			lev[0]=0; lev[1]=1; lev[2]=2;
			random_shuffle(lev,lev+3);
		} else {
			rep(i,0,3) lev[i]=rnd(3);
		}
		suc:;
		dfs2(rt,-1);
		rep(i,0,m) {
			lab[i]%=3; if (lab[i]<=0) lab[i]+=3;
		}
		rep(i,0,n) sm[i]=0;
		rep(i,0,m) sm[x[i]]+=lab[i],sm[y[i]]+=lab[i];
		bool fg=1;
		rep(i,0,m) fg&=sm[x[i]]!=sm[y[i]];
		if (fg) {
			rep(i,0,m) printf("%d %d %d\n",x[i],y[i],lab[i]);
			break;
		}
	}
}