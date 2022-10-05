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
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
using namespace std;                    
const ll maxn=1e6+12,inf=2e9,mod=1e8; 
vector<int>g[maxn];
int n,p[maxn],sz[maxn];
ll ans;
bool used[maxn];
pair<int , int > a[maxn];
int get(int v){
	if(p[v]==v)
		return v;
	return p[v]=get(p[v]);	
}
int main(){
  	
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].f);
		a[i].s=i;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sz[i]=1,p[i]=i,used[i]=0;
	for(int i=1;i<=n;i++){
		int u=a[i].s,val=a[i].f,v;
		//cout<<v<<" ";
		used[u]=1;
		for(int j=0;j<g[u].size();j++){
			int to=g[u][j];		
			if(used[to]){
				to=get(to);
				v=get(u);
				ans+=1ll*sz[to]*sz[v]*val;
				if(sz[v]>sz[to]){
					sz[v]+=sz[to];
					p[to]=v;
				}else{
				    sz[to]+=sz[v];
					p[v]=to;
				}
			}
		}
	}
	//cout<<ans<<endl;
    reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sz[i]=1,p[i]=i,used[i]=0;
	for(int i=1;i<=n;i++){
		int u=a[i].s,val=a[i].f,v;
		//cout<<v<<" ";
		used[u]=1;
		for(int j=0;j<g[u].size();j++){
			int to=g[u][j];		
			if(used[to]){
				to=get(to);
				v=get(u);
				ans-=1ll*sz[to]*sz[v]*val;
				if(sz[v]>sz[to]){
					sz[v]+=sz[to];
					p[to]=v;
				}else{
				    sz[to]+=sz[v];
					p[v]=to;
				}
			}
		}
	}
	cout<<ans;
}