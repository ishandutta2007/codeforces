//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
	return o<<'('<<x.first<<','<<x.second<<')';
}
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
ll qpow(ll a,ll b){
	ll ans=1;
	while(b--)ans=ans*a;
	return ans;
}
#define int ll
map<int,int> b;
void Solve(){
	int n=read(),m=read(); b.clear();
	for(int i=2;i*i<=m;i++)
	while(m%i==0){
		m/=i;
		b[i]++;
	}
	if(m>1)b[m]++;
	ll ans=1;
	for(auto i:b){
		//orz(i);
		int t=n,cnt=0;
		while(t%i.fi==0)cnt++,t/=i.fi;
		int x=min(cnt,i.se-1); //orz(cnt); orz(x);
		ans=max(ans,n/qpow(i.fi,cnt-x));
	}
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}