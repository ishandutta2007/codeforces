//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=300010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
set<int> st;
int a[N]; vector<int> b[N],v,v2;
int f[N];
void Solve(){
	int n=read();
	repeat(i,1,n+1)b[i].clear();
	repeat(i,1,n+1)a[i]=read(),b[a[i]].push_back(i);
	st.clear();
	st.insert(0); st.insert(n+1);
	int x1=0,x2=0,m=inf;
	repeat(i,1,n+1){
		if(b[i].empty())m=min(m,i);
		v.clear(); v2.clear();
		for(auto x:b[i]){
			auto ptr=st.lower_bound(x);
			int pre=*prev(ptr);
			int nxt=*ptr;
			//cout<<x<<' '<<pre<<' '<<nxt<<endl;
			if(pre!=x-1 && nxt!=x+1)
				x1=max(x1,nxt-pre-2);
			v.push_back(pre);
			v2.push_back(nxt-pre-2);
		}
		if(b[i].size()>=2){
			sort(v2.begin(),v2.end());
			v.erase(unique(v.begin(),v.end()),v.end());
			if(v.size()>1){
				x2=max(x2,v2.rbegin()[1]+1);
			}
			else{
				x2=max(x2,v2[0]);
			}
		}
		for(auto x:b[i]){
			st.insert(x);
		}
	}
	repeat(i,1,n+1){
		f[i]+=f[i-1];
		if(2<=i && i<=x1)
			putchar('0');
		else if(i<=n-m+1)
			putchar('0');
		else if(i<=x2)
			putchar('0');
		else putchar('1');
	}
	puts("");
	//cout<<x1<<' '<<m<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}