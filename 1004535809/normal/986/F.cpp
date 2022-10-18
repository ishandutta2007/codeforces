//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=1e4;
const int MAXK=1e5;
const int MAXV=3.163e7;
int qpow(int x,int e,int mod){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%mod) if(e&1) ret=1ll*ret*x%mod;
	return ret;
}
int qu,pr[MAXV/8+5],prcnt,vis[MAXV+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;if(i%pr[j]==0) break;
		}
	}
}
int res[MAXN+5];
map<ll,vector<pair<ll,int> > > mpv;
vector<ll> decomp(ll v){
	vector<ll> ret;
	for(int i=1;i<=prcnt;i++) if(v%pr[i]==0){
		ret.pb(pr[i]);
		while(v%pr[i]==0) v/=pr[i];
	} if(v>1) ret.pb(v);
	return ret;
}
ll dis[MAXK+5];
int main(){
	sieve(MAXV);scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		ll n,k;scanf("%lld%lld",&n,&k);
		if(k!=1) mpv[k].pb(mp(n,i));
	}
	for(auto it:mpv){
		ll v=it.fi;vector<pair<ll,int> > qv=it.se;
		vector<ll> pr=decomp(v);
		if(pr.size()==1){
			for(pair<ll,int> p:qv) res[p.se]=(p.fi%pr[0]==0);
		} else if(pr.size()==2){
			ll x=pr[0],y=pr[1],ivy=qpow(y%x,x-2,x);
			for(pair<ll,int> p:qv){
				int bmin=1ll*(p.fi%x)*ivy%x;
				res[p.se]=(p.fi>=1ll*bmin*y);
			}
		} else {
			int x=pr[0];memset(dis,63,sizeof(dis));dis[0]=0;
			priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
			q.push(mp(0,0));
			while(!q.empty()){
				pair<ll,int> p=q.top();q.pop();
				int cur=p.se;
				for(int i=1;i<pr.size();i++){
					if(dis[(cur+pr[i])%x]>dis[cur]+pr[i]){
						dis[(cur+pr[i])%x]=dis[cur]+pr[i];
						q.push(mp(dis[(cur+pr[i])%x],(cur+pr[i])%x));
					}
				}
			}
			for(pair<ll,int> p:qv) res[p.se]=(p.fi>=dis[p.fi%x]);
		}
	}
	for(int i=1;i<=qu;i++) printf("%s\n",(res[i])?"YES":"NO");
	return 0;
}