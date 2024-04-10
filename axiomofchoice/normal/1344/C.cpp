#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int n,m;
int deg[N];
queue<int> q;
vector<int> a[N],b[N];
char ans[N];
bool vis_a[N],vis_b[N];
void del_a(int x){
	if(vis_a[x])return;
	vis_a[x]=1;
	for(auto p:a[x])
		del_a(p);
}
void del_b(int x){
	if(vis_b[x])return;
	vis_b[x]=1;
	for(auto p:b[x])
		del_b(p);
}
signed main(){
	cin>>n>>m;
	while(m--){
		int x,y; cin>>x>>y; x--,y--;
		a[x]+=y; b[y]+=x;
		deg[y]++;
	}
	repeat(i,0,n)
	if(deg[i]==0)
		q.push(i);
	int cnt=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		cnt++;
		for(auto p:a[x])
		if(--deg[p]==0)
			q.push(p);
	}
	if(cnt!=n)cout<<-1<<endl,exit(0);
	int ANS=0;
	repeat(i,0,n){
		if(vis_a[i] || vis_b[i])ans[i]='E';
		else{
			ans[i]='A';
			ANS++;
		}
		del_a(i);
		del_b(i);
	}
	cout<<ANS<<endl<<ans;
	return 0;
}