// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=(1<<22)+123,inf=1e9,mod=1e9+7;
vector<int>g[maxn];
int n,m,a[maxn],ans;
bool used[maxn][2],was[maxn];
void dfs(int v,int k){
	if(used[v][k])
		return;
	used[v][k]=1;
	if(k==1){
		dfs(v,0);
	}else{
		for(int i=0;i<n;i++){
			if( ((1<<i)&v) == 0 ){
				dfs( v|(1<<i) ,0);    
			}
		}
		if(was[(1<<n)-v-1])
			dfs( (1<<n)-v-1,1 );          
	}
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		was[a[i]]=1;
	}   
	for(int i=1;i<=m;i++){
		if(!used[a[i]][1]){
			dfs(a[i],1);
			ans++;
		}
	}   
	cout<<ans;
}