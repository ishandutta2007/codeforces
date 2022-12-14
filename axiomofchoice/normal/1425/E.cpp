#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct ST{
	#define logN 21
	#define U(x,y) min(x,y)
	ll a[N][logN];
	void init(int in[],int n){
		repeat(i,0,n)
			a[i][0]=in[i];
		repeat(k,1,logN)
		repeat(i,0,n-(1<<k)+1)
			a[i][k]=U(a[i][k-1],a[i+(1<<(k-1))][k-1]);
	}
	ll query(int l,int r){
		int s=31-__builtin_clz(r-l+1);
		return U(a[l][s],a[r-(1<<s)+1][s]);
	}
}st,st2;
int a[N],s[N],d[N],cyc[N];
int sum(int l,int r){return s[r]-s[l-1];}
void Solve(){
    int n=read(),k=read();
    repeat(i,1,n+1)a[i]=read(),s[i]=s[i-1]+a[i];
    repeat(i,1,n+1)d[i]=read();
    st.init(a,n+1);
    st2.init(d,n+1);
    int ans=0;
    ans=max(ans,a[n]-d[n]);
    if(k==0){
        repeat(i,1,n+1)ans=max(ans,sum(i,n)-d[i]);
    }
    if(k==1){
        repeat(i,2,n+1)ans=max(ans,sum(i,n)-d[i]);
        repeat(i,1,n){
            ans=max(ans,sum(i,n)-d[i]-st.query(i+1,n));
            ans=max(ans,sum(i,n)-d[i]-st2.query(i+1,n));
        }
        repeat(i,1,n)cyc[i]=sum(1,i)-st2.query(1,i);
        repeat(i,1,n)cyc[i]=max(cyc[i],cyc[i-1]);
        repeat(i,2,n+1)ans=max(ans,cyc[i-1]+max(0ll,sum(i,n)-d[i]));
        ans=max(ans,sum(1,n-1)-*min_element(d+1,d+n)+max(0ll,a[n]-d[n]));
    }
    if(k>=2){
        ans=max(ans,sum(1,n)-*min_element(d+1,d+n));
    }
    cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}