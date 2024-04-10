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
deque<int> a;
void Solve(){
	int n=read(),l=read();
	repeat(i,0,n)a.push_back(read());
	lf v1=1,v2=1,x1=0,x2=l,ans=0;
	while(!a.empty()){
		lf t1=(a.front()-x1)/v1;
		lf t2=(x2-a.back())/v2;
		if(t1<t2){
			x1=a.front(); a.pop_front();
			v1++;
			ans+=t1;
			x2-=t1*v2;
		}
		else{
			x2=a.back(); a.pop_back();
			v2++;
			ans+=t2;
			x1+=t2*v1;
		}
	}
	ans+=(x2-x1)/(v1+v2);
	printf("%.12f\n",ans);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}