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
const int N=1000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
char s[N],t[N];
int fs[26],ft[26];
void Solve(){
	int n=read(),k=read();
	scanf("%s%s",s,t);
	sort(s,s+n);
	sort(t,t+n);
	repeat(i,0,n){
		if(s[i]>t[i]){puts("No"); return;}
	}
	fill(fs,fs+26,n);
	fill(ft,ft+26,n);
	repeat_back(i,0,n){
		fs[s[i]-'a']=i;
		ft[t[i]-'a']=i;
	}
	repeat_back(i,0,25){
		fs[i]=min(fs[i],fs[i+1]);
		ft[i]=min(ft[i],ft[i+1]);
	}
//	orzeach(fs);
//	orzeach(ft);
	repeat(i,0,26)
		if((fs[i]-ft[i])%k!=0){puts("No"); return;}
	puts("Yes");
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}