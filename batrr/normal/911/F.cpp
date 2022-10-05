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
using namespace std;                    
const ll maxn=2e6+1,inf=2e9,mod=1e9+7;
vector<int>g[maxn];
ll n,a=1,b=1,d[maxn][3],sum;
bool used[maxn];
vector< pair < int , int > > ans;
void dfs(int v,int p,int lvl,int type){
	d[v][type]=lvl;     
	if(type==0){
		if(d[v][type]>d[a][type])
			a=v;
	}
    if(type==1){
		if(d[v][type]>d[b][type])
			b=v;
	}
    for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p)
			dfs(to,v,lvl+1,type);
	} 
}       
void del(int v, int p){
	bool res=true;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			del(to,v);
			if(used[to]==false)
				res=false;
		}
	}
	if(res==true && v!=a && v!=b){
		if(d[v][1]>d[v][2])
			ans.pb(mp(a,v));
		else
			ans.pb(mp(b,v));
		sum+=max(d[v][1],d[v][2]);
		used[v]=1;
	}
}
void dd(int v, int p){
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(used[to]==false && p!=to){
			dd(to,v);
		}
	}
	sum+=d[v][1];
	ans.pb(mp(a,v));
	used[v]=1;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u);	
	}
	dfs(1,1,0,0);	
	dfs(a,a,0,1);
	dfs(b,b,0,2);
	del(a,a);
	dd(a,a);
	cout<<sum<<endl;
	for(int i=0;i<ans.size()-1;i++)
		cout<<ans[i].f<<" "<<ans[i].s<<" "<<ans[i].s<<endl;
}