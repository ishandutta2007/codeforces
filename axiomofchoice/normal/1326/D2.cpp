#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
#define inline __inline __attribute__((always_inline))
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;}
typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=2000010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int len[N],nxt[N],pre[N],cnt[N];
char s[N],s2[N]; //s
int ans=0,nn,p,x;
void solve(char s[]){
	int n=strlen(s)*2+1;
	repeat_back(i,0,n){
		if(i%2==0)s[i+1]='*';
		else s[i+1]=s[i/2];
	}
	n+=2;
	s[0]='#'; s[n-1]=0;
	len[0]=0;
	int mx=0,id=0;
	repeat(i,1,n-1){
		if(i<mx)len[i]=min(mx-i,len[2*id-i]);
		else len[i]=1;
		while(s[i-len[i]]==s[i+len[i]])len[i]++;
		if(len[i]+i>mx){
			mx=len[i]+i;
			id=i;
		}
		int l=(i-len[i]+1)/2;
		int r=l+len[i]-1-1;
		if(l>r)continue;
		//cout<<l<<' '<<r<<endl;
		if((l==0 || r==nn-1-x-x )&& ans<len[i]-1){
			ans=len[i]-1,p=(l==0);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); //freopen("in.txt","r",stdin);
	int T=read(); gets(s);
	while(T--){
		gets(s); ans=0;
		nn=strlen(s);
		strcpy(s2,s);
		x=nn;
		repeat(i,0,nn){
			if(s[i]!=s[nn-1-i])
				x=min(x,i);
		}
		if(x==nn){
			puts(s);
			continue;
		}
		s2[nn-x]=0;
		//puts(s2+x);
		solve(s2+x);
		//cout<<x<<' '<<ans<<' '<<p<<endl;
		repeat(i,0,nn)
			if(i<x || i>nn-1-x ||
			(p==1 && i<x+ans) ||
			(p==0 && i>nn-1-x-ans))putchar(s[i]);
		puts("");
	}
	return 0;
}