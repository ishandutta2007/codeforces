#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=[]{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
#endif
const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int t,n,j;
bool f[N],g[N];
vector<int> a[N];
void find(){
	cout<<"IMPROVE"<<endl;
	repeat(i,0,n)if(!g[i]){cout<<i+1; break;}
	repeat(i,0,n)if(!f[i]){cout<<' '<<i+1<<endl; break;}
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		repeat(i,0,n)a[i].clear();
		fill(f,f+n,0);
		fill(g,g+n,0);
		int cnt=0;
		repeat(i,0,n){
			int m,x; cin>>m;
			repeat(j,0,m)cin>>x,x--,a[i].push_back(x);
			for(auto p:a[i]){
				if(!f[p]){
					f[p]=1;
					g[i]=1;
					cnt++;
					break;
				}
			}
		}
		if(cnt==n)cout<<"OPTIMAL"<<endl;
		else find();
	}
	return 0;
}