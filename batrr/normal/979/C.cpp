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
const ll maxn=1e6+123,inf=1e8,mod=1e9+7,block=200,N=5000+123;
vector<int>g[maxn];
ll n,x,y,ans,cnt[maxn],bad[maxn];
void dfs (int v, int p) {
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p){
			dfs (to, v);
			if(!bad[to])
				cnt[v]+=cnt[to];
			else
				bad[v]=1;
		}
	}
	cnt[v]++;
}   
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif
	cin>>n>>x>>y;
	for(int i=1;i<n;i++){
		int v,u;
		cin>>v>>u; 
		g[v].pb(u);
		g[u].pb(v);
	}
	bad[y]=1;
	dfs(x,x);
	cout<<n*(n-1)-cnt[y]*cnt[x];
}