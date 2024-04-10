// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e18,mod=1e9+7,LOG=20;
vector<int>g[maxn];
map<ll,ll>dp1[maxn],dp2[maxn];// dp1[v][cnt]=c1+c2+c3 dp2[v][c1]=cnt1
ll n,a[maxn],ans[maxn];
void Merge(int v,int u){
	if(dp2[v].size()<dp2[u].size()){
		swap(dp1[v],dp1[u]);
        swap(dp2[u],dp2[v]);
    }
	for(map<ll,ll> :: iterator it=dp2[u].begin();it!=dp2[u].end();it++){
		ll c=(*it).f,cnt=(*it).s;
		dp1[v][dp2[v][c]]-=c;
		dp2[v][c]+=cnt;
		dp1[v][dp2[v][c]]+=c;
	}                    
	dp1[u].clear();
	dp2[u].clear();
}
void dfs(int v,int pr){
	dp1[v][1]=a[v];
	dp2[v][a[v]]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=pr){
			dfs(to,v);
			Merge(v,to);
		}
	}                                
    ans[v]=(*dp1[v].rbegin()).s;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
        g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
}