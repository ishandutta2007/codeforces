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
const ll maxn=1e6+123,inf=1e8,mod=1e9+7,block=200,N=2053;
vector<int>g[maxn];
int n,ans;
bool used[maxn];
void dfs(int v,int p){
	int cnt=0;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs(to,v);
			if(!used[to])
				cnt++;
		}
	}
	cnt++;
	if(cnt%2==0)
		ans++,used[v]=1;
}


int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
//	#else
//		freopen ("jumper.in", "r", stdin);
//		freopen ("jumper.out", "w", stdout);
	#endif               
	cin>>n;                                                       
	for(int i=1;i<n;i++){                                    
		int u,v;
		cin>>v>>u; 
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1,1);
	if(used[1])
		cout<<ans-1;
	else
		cout<<-1;
}