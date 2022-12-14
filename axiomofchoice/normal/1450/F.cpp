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
int a[N],cnt[N];
map<int,int> same;
vector<pii> dif;
void Solve(){
	int n=read(); fill(cnt,cnt+n+1,0);
	same.clear(); dif.clear();
	repeat(i,0,n){
		a[i]=read();
		cnt[a[i]]++;
	}
	int t=*max_element(cnt,cnt+n+1);
	if(t*2-1>n){puts("-1"); return;}
	int pre=0,mx=0,sum=0,ans=0;
	a[n]=a[n-1];
	repeat(i,0,n){
		if(a[i]==a[i+1]){
			if(a[pre]==a[i]){
				same[a[i]]++;
			}
			else dif.push_back({a[pre],a[i]});
			ans++;
			pre=i+1;
		}
	}
	ans--;
	for(auto i:same){
		sum+=i.se;
		if(i.se>mx){
			t=i.fi;
			mx=i.se;
		}
	}
	for(auto i:dif){
		if(i.fi!=t && i.se!=t)
			mx--,sum--;
	}
	while(mx*2-1>sum){
		ans++,mx--,sum--;
	}
	printf("%d\n",ans);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}