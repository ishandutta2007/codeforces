#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
//#define int ll
vector<int> v;
int ans[N];
char s[10];
void Solve(){
	int n=read(); int f=true;
	repeat(i,0,n*2){
		scanf("%s",s);
		if(*s=='+')v.push_back(i);
		else{
			int x=read();
			if(v.empty())f=false;
			else ans[v.back()]=x,ans[i]=-x,v.pop_back();
		}
	}
	if(!v.empty())f=false;
	if(f){
		repeat(i,0,n*2){
			if(ans[i]>0){
				if(!v.empty() && v.back()<ans[i])f=false;
				else v.push_back(ans[i]);
			}
			else{
				if(ans[i]+v.back()!=0)f=false;
				else v.pop_back();
			}
		}
	}
	if(f){
		cout<<"YES"<<endl;
		repeat(i,0,n*2)if(ans[i]>0)cout<<ans[i]<<' ';
	}
	else{
		cout<<"NO"<<endl;
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}