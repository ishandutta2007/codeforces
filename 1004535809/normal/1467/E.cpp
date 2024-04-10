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
const int MAXN=2e5;
int n,a[MAXN+5],key[MAXN+5],hs[MAXN+5],num=0;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
set<int> st[MAXN+5];
int bgt[MAXN+5],edt[MAXN+5],tim=0;
void dfs0(int x,int f){
	bgt[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs0(y,x);
	} edt[x]=tim;
}
bool dp[MAXN+5],out[MAXN+5],ok[MAXN+5];
void dfs1(int x,int f){
	dp[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs1(y,x);dp[x]&=dp[y];
	}
	set<int>::iterator it=st[a[x]].upper_bound(bgt[x]);
	if(it!=st[a[x]].end()&&(*it)<=edt[x]) dp[x]=0;
}
void dfs2(int x,int f){
	int cnt0=0,cnt1=0,pos0=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(y==f){
			if(!out[x]) cnt0++,pos0=y;
			else cnt1++;
		} else {
			if(!dp[y]) cnt0++,pos0=y;
			else cnt1++;
		}
	} st[a[x]].erase(st[a[x]].find(bgt[x]));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		if(cnt0>=2||(cnt0==1&&pos0!=y)||(!st[a[x]].empty()&&
		((*st[a[x]].begin())<bgt[y]||(*st[a[x]].rbegin())>edt[y]))) out[y]=0;
		else out[y]=1;
	} st[a[x]].insert(bgt[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		ok[y]=(dp[y]&&out[y]&&st[a[y]].size()==1);dfs2(y,x);
	}
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);adde(u,v);adde(v,u);} 
	sort(key+1,key+n+1);for(int i=1;i<=n;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(hs+1,hs+num+1,a[i])-hs;dfs0(1,0);
	for(int i=1;i<=n;i++) st[a[i]].insert(bgt[i]);
	dfs1(1,0);out[1]=1;ok[1]=dp[1];dfs2(1,0);
//	for(int i=1;i<=n;i++) printf("%d\n",out[i]);
//	for(int i=1;i<=n;i++) printf("%d\n",ok[i]);
	int ans=0;for(int i=1;i<=n;i++) ans+=ok[i];printf("%d\n",ans);
	return 0;
}