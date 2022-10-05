// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e8,mod=1e9+7,block=200,N=2053;
vector<int>g[maxn],v[maxn];
ll n,m,k,s,a[maxn],dis[maxn];
bool used[maxn];
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	cin>>n>>m>>k>>s;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u);
	}   
	
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++)
			used[i]=0,dis[i]=1e6;
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(a[i]==j){
				used[i]=1;
				dis[i]=0;
				q.push(i);
			}
		}
		while(!q.empty()){
			int v=q.front();
			q.pop();
			for(int i=0;i<g[v].size();i++){
				int to=g[v][i];
				if(!used[to]){
					used[to]=1;
					dis[to]=dis[v]+1;
					q.push(to);
				}
			}
		}
		for(int i=1;i<=n;i++)
   			v[i].pb(dis[i]);
   	}  
   	for(int i=1;i<=n;i++){
   		sort(v[i].begin(),v[i].end());
   		ll ans=0;
   		for(int j=0;j<s;j++)
   			ans+=v[i][j];
   		cout<<ans<<" ";
   	}
}