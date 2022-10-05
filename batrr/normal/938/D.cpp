#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>
 
#include <ctime>
#include <cassert> 
                    
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
const ll maxn=3e5+13,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
#define int long long
vector< pair < ll , ll > > g[maxn];
ll n,m,ans[maxn];
signed main(){
	//ios_base:: sync_with_stdio(false);            
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&v,&u,&w);
		w*=2;  
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&ans[i]);
	
	set< pair < ll , ll > > st;
	for(int i=1;i<=n;i++)
		st.insert(mp(ans[i],i));
	while(!st.empty()){
		int v=(*st.begin()).s;
		st.erase(st.begin());
		for(int i=0;i<g[v].size();i++){
			ll to=g[v][i].f,w=g[v][i].s;
			if(ans[to]>ans[v]+w){
				st.erase(mp(ans[to],to));
				ans[to]=ans[v]+w;
				st.insert(mp(ans[to],to));
			}
		}
	}		
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
}