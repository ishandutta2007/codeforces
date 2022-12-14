#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct LR{
	int y,l,r;
}a[N];
struct event{
	int x,y,d;
};
struct seg{
	#define U(a,b) (a+b) //????
	ll a0=0; //???????
	int n; ll a[1024*1024*2]; //????2^k???????inn
	void init(int inn){ //??
		for(n=1;n<inn;n<<=1);
		repeat(i,0,n)a[n+i]=0;
		repeat_back(i,1,n)up(i);
	}
	void up(int x){
		a[x]=U(a[x<<1],a[(x<<1)^1]);
	}
	void update(int x,ll k){ //??x??k
		a[x+=n]+=k; //????????
		while(x>>=1)up(x);
	}
	ll query(int l,int r){ //????
		ll ans=a0;
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)ans=U(ans,a[l^1]); //l^1???l+1
			if(r & 1)ans=U(ans,a[r^1]); //r^1???r-1
		}
		return ans;
	}
}tr;
vector<event> e;
void Solve(){
	int n=read(),m=read(); tr.init(1000010);
	ll ans=1;
	repeat(i,0,n){
		a[i].y=read();
		a[i].l=read();
		a[i].r=read();
	}
	sort(a,a+n,[](LR a,LR b){return a.y<b.y;});
	repeat(i,0,m){
		int x=read(),u=read(),d=read();
		int t=(u==0)+(d==1000000);
		e<<(event){x,u,1};
		e<<(event){x,d+1,-1};
		ans+=(t==2);
	}
	sort(e.begin(),e.end(),[](event a,event b){return a.y>b.y;});
	repeat(i,0,n){
		int t=(a[i].l==0)+(a[i].r==1000000);
		while(!e.empty() && e.back().y<=a[i].y){
			tr.update(e.back().x,e.back().d);
			e.pop_back();
		}
		ans+=tr.query(a[i].l,a[i].r);
		ans+=(t==2);
	}
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}