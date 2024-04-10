#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct node{
    int x,y,w;
};
struct CC{
	static const int N=100010;
	ll fac[N],inv[N];
	CC(){
		fac[0]=1;
		repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=qpow(fac[N-1],mod-2,mod);
		repeat_back(i,1,N)inv[i-1]=inv[i]*i%mod;
	}
	ll operator()(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod*inv[b]%mod;
	}
	ll A(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod;
	}
}C;
vector<node> v;
int s[N][N];
int sum(int x1,int y1,int x2,int y2){
    x1--,y1--;
    x1=max(0ll,x1);
    y1=max(0ll,y1);
    x2=min(1009ll,x2);
    y2=min(1009ll,y2);
    return s[x2][y2]-s[x1][y2]-s[x2][y1]+s[x1][y1];
}
void Solve(){
    int n=read(),m=read(),r=read();
    repeat(i,0,n){
        int x=read(),y=read(),w=read();
        v<<(node){x,y,w};
        s[x][y]++;
    }
    repeat(i,1,N)
    repeat(j,1,N)
        s[i][j]+=s[i][j-1];
    repeat(i,1,N)
    repeat(j,1,N)
        s[i][j]+=s[i-1][j];
    int ans=0;
    repeat(i,0,n){
        int A=sum(v[i].x-r,v[i].y-r,v[i].x+r,v[i].y+r);
        ans+=v[i].w*v[i].w%mod*((C(n,m)-C(n-A,m))%mod)%mod;
        //cout<<sum(v[i].x-r,v[i].y-r,v[i].x+r,v[i].y+r)<<endl;
    }
    //cout<<ans<<endl;
    repeat(i,0,n)
    repeat(j,i+1,n){
        int a=sum(v[i].x-r,v[i].y-r,v[i].x+r,v[i].y+r);
        int c=sum(v[j].x-r,v[j].y-r,v[j].x+r,v[j].y+r);
        int b=0;
        int x1=v[i].x,y1=v[i].y;
        int x2=v[j].x,y2=v[j].y;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        x1+=r,y1+=r,x2-=r,y2-=r;
        //cout<<x2<<' '<<y2<<' '<<x1<<' '<<y1<<endl;
        if(x2<=x1 && y2<=y1)
            b=sum(x2,y2,x1,y1);
        a-=b,c-=b; int d=n-a-b-c;
        //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
        int now=C(n,m)-C(c+d,m)-C(a+d,m)+C(d,m);
        //cout<<now<<endl;
        now%=mod;
        ans+=2*v[i].w*v[j].w%mod*now%mod;
    }
    ans%=mod; ans+=mod; ans%=mod;
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