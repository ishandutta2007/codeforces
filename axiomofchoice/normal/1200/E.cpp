#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
const int hashxor=rnd()%10000;
struct Hash{
	vector<ll> a[2],p[2];
	const ll b=257,m[2]={1000000007,998244353};
	Hash(){repeat(i,0,2)a[i]={0},p[i]={1};}
	void push(const string &s){
		repeat(i,0,2)
		for(auto c:s){
			c^=hashxor;
			a[i].push_back((a[i].back()*b+c)%m[i]);
			p[i].push_back((p[i].back()*b+0)%m[i]);
		}
	}
	pair<ll,ll> get(int l,int r){
		#define q(i) (a[i][r+1]-a[i][l]*p[i][r-l+1]%m[i]+m[i])%m[i]
		return {q(0),q(1)};
	}
	int size(){return a[0].size()-1;}
	pair<ll,ll> prefix(int len){return get(0,len-1);}
	pair<ll,ll> suffix(int len){return get(size()-len,size()-1);}
}h;
string ans;
void push(const string &s){
	ans+=s;
	h.push(s);
}
string s;
signed main(){
	int n; cin>>n;
	while(n--){
		cin>>s;
		Hash h2; h2.push(s);
		repeat_back(i,0,min(h.size(),h2.size())+1){
			if(i==0 || h.suffix(i)==h2.prefix(i)){
				push(s.substr(i,-1));
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}