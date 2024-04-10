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
#define Bystro ios_base::sync_with_stdio(0);

using namespace std;                    
const ll maxn=2e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
int t[4*maxn][2];
vector<int>g[maxn];
int tin[maxn],tout[maxn],timer,depth[maxn];
int n,q,a[maxn];
void dfs(int v, int p){
	tin[v]=++timer;
	depth[v]=depth[p]+1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs(to,v);
		}
	}

	tout[v]=timer; 
}                         
void up(int v, int tl, int tr , int l, int r , int val,int  k){
	if(l>r)
		return;
	if(tl==l && tr==r){
		t[v][k]+=val;
		return;
	}
	int tm=(tl+tr)/2;         
	up(v+v,tl,tm,l,min(tm,r),val,k);
	up(v+v+1,tm+1,tr,max(tm+1,l),r,val,k);
}
int get(int v, int tl, int tr , int  x ,int k){
	if(tl==tr)
		return t[v][k];
	int tm=(tl+tr)/2;
	if(x<=tm)                          
		return t[v][k]+get(v+v,tl,tm,x,k);
	else
		return t[v][k]+get(v+v+1,tm+1,tr,x,k);
}
int main(){           
	//stdi
	Bystro
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,1);
	while(q--){
		int type,x,val;
		cin>>type;
		if(type==1){
			cin>>x>>val;                   
			up(1,1,n,tin[x],tout[x],val,  depth[x]%2 );  
			up(1,1,n,tin[x],tout[x],-val, 1-depth[x]%2 );
		}
		else
		{
			cin>>x;
			cout<< a[x] + get(1,1,n,tin[x], depth[x]%2 )<<endl;
		}
	}	
}