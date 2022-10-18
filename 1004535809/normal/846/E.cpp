#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const ll INF=3e18;
const int MAXN=1e5;
int n;
ll a[MAXN+5],b[MAXN+5],dp[MAXN+5];
int to[MAXN+5],hd[MAXN+5],nxt[MAXN+5],ec=0;
ll cst[MAXN+5];
void adde(int u,int v,ll w){to[++ec]=v;cst[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
ll dfs(int x){
	ll cur=b[x]-a[x];
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];ll z=cst[e];
		ll c=dfs(y);
		if(c>0) cur+=c;
		else{
			if(INF/z<=-c) cur=-INF;
			else{
				cur+=z*c;
				if(cur<-INF) cur=-INF;
			}
		}
	}
	return cur;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++){
		int x;ll w;scanf("%d%lld",&x,&w);adde(x,i,w);
	}
	ll t=dfs(1);
	if(t>=0) puts("YES");
	else puts("NO");
	return 0;
}