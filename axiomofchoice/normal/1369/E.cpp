#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define endl "\n"
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int w[N];
vector<int> ans;
vector<pii> e[N];
queue<int> q;
bool vis[N],in_ans[N];
void Solve(){
	int n=read(),m=read();
	repeat(i,0,n)w[i]=read();
	repeat(i,0,m){
		int x=read()-1,y=read()-1;
		e[x].push_back({y,i}); w[x]--;
		e[y].push_back({x,i}); w[y]--;
	}
	repeat(i,0,n)
		if(w[i]>=0)q.push(i),vis[i]=1;
	while(!q.empty()){
		int food=q.front(); q.pop();
		for(auto p:e[food]){
			if(!in_ans[p.se])ans.push_back(p.se),in_ans[p.se]=1;
			if(!vis[p.fi]){
				w[p.fi]++;
				if(w[p.fi]>=0){
					vis[p.fi]=1;
					q.push(p.fi);
				}
			}
		}
	}
	if((int)ans.size()==m){
		cout<<"ALIVE"<<endl;
		repeat_back(i,0,ans.size())cout<<ans[i]+1<<' ';
	}
	else cout<<"DEAD"<<endl;
}
signed main(){
	for(int T=1||read();T--;)Solve();
	return 0;
}