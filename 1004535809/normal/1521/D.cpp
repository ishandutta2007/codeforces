#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
vector<pair<pii,pii> > res;
void clear(){for(int i=1;i<=n;i++) hd[i]=0;ec=0;res.clear();}
struct dat{int op,bt1,bt2;} a[MAXN+5];
void dfs(int x,int f){
	int sum=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);sum+=(a[y].op==1);
	} if(sum>=2){
		int p=0,q=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(a[y].op==1){
				if(!p) p=y;
				else if(!q) q=y;
			}
		} assert(p&&q);
		a[x].op=2;a[x].bt1=a[p].bt2;a[x].bt2=a[q].bt2;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(y==p||y==q) continue;
			if(a[y].op==1){
				res.pb(mp(mp(x,y),mp(y,a[x].bt2)));
				a[x].bt2=a[y].bt2;
			} else {
				res.pb(mp(mp(x,y),mp(a[y].bt1,a[x].bt2)));
				a[x].bt2=a[y].bt2;
			}
		}
	} else if(sum==1){
		int p=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(a[y].op==1) p=y;
		} a[x].op=1;a[x].bt1=x;a[x].bt2=a[p].bt2;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(a[y].op==2){
				res.pb(mp(mp(x,y),mp(a[y].bt1,a[x].bt2)));
				a[x].bt2=a[y].bt2;
			}
		}
	} else {
		int p=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(a[y].op==2) p=y;
		} if(!p) return a[x].op=1,a[x].bt1=a[x].bt2=x,void();
		a[x].op=1;a[x].bt1=x;a[x].bt2=a[p].bt2;
		res.pb(mp(mp(x,p),mp(x,a[p].bt1)));
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			if(y^p){
				res.pb(mp(mp(x,y),mp(a[y].bt1,a[x].bt2)));
				a[x].bt2=a[y].bt2;
			}
		}
	} //printf("%d %d %d %d\n",x,a[x].op,a[x].bt1,a[x].bt2);
}
void solve(){
	scanf("%d",&n);clear();
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);printf("%d\n",res.size());
	for(int i=0;i<res.size();i++) printf("%d %d %d %d\n",res[i].fi.fi,res[i].fi.se,res[i].se.fi,res[i].se.se);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}