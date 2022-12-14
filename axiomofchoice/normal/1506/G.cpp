// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
char s[N];
deque<int> pos[256];
bool ans[N];
deque<pii> a,b;
void done(int t){
	ans[a[t].se]=1;
	repeat(i,0,a.size())
	if(a[i].fi!=a[t].fi)
		b.push_back(a[i]);
	a=move(b);
}
set<char> st;
bool work(char c){
	st.clear();
	int t=-1;
	repeat(i,0,a.size()){
		if(a[i].fi==c){t=i; break;}
		st.insert(a[i].fi);
	}
	if(t==-1)return false;
	repeat(i,t+1,a.size())
	if(st.count(a[i].fi))
		st.erase(a[i].fi);
	if(st.empty()){
		repeat(j,0,t)a.pop_front();
		done(0);
		return true;
	}
	return false;
}
void Solve(){
	scanf("%s",s);
	int n=strlen(s);
	repeat(i,0,n)a.push_back({s[i],i});
	fill(ans,ans+n,0);
	while(!a.empty()){
		repeat_back(c,'a','z'+1)
			if(work(c))break;
	}
	repeat(i,0,n)if(ans[i])
		putchar(s[i]);
	puts("");
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}