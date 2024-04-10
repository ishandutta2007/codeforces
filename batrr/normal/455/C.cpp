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
const ll maxn=3e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;

vector<int> g[maxn];
int p[maxn],sz[maxn],s[maxn];                                            
int n,m,q;
bool used[maxn];
int getp(int v){
	if(p[v]==v)
		return v;
	p[v]=getp(p[v]);
	return p[v];
}
void Merge(int a, int b){
	a=getp(a);
    b=getp(b);
    if(a==b)
    	return ;
    if(sz[a]>sz[b])
    	swap(a,b);
    p[a]=b;
    sz[b]+=sz[a];
    s[b]= max(s[b]%2+s[a]%2+s[b]/2+s[a]/2+1, max(s[b],s[a]) );
}
int main(){           
	for(int i=0;i<maxn;i++)
		p[i]=i,sz[i]=1;
	//stdi
	Bystro
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
	}                
	for(int i=1;i<=n;i++){
		if(used[i])
			continue;
		int last,dia;
		queue< pair < pair< int , int > , int > > bfs;
		
		bfs.push(mp(mp(i,i),0));
		while(!bfs.empty()){      
			int v=bfs.front().f.f;
			int pr=bfs.front().f.s;
			int dis=bfs.front().s;
			bfs.pop();
			for(int i=0;i<g[v].size();i++){
				int to=g[v][i];
				if(to==pr)
					continue;
				bfs.push(mp(mp(to,v),dis+1));
			}
			last=v;
		}

		bfs.push(mp(mp(last,last),0));
		
		while(!bfs.empty()){
			int v=bfs.front().f.f;
			int pr=bfs.front().f.s;
			int dis=bfs.front().s;
			used[v]=1;
			
			bfs.pop();
			for(int i=0;i<g[v].size();i++){
				int to=g[v][i];
				if(to==pr)
					continue;
				sz[last]++;
				p[to]=last;
				bfs.push(mp(mp(to,v),dis+1));
			}
			dia=dis;
		}

		s[last]=dia;
	}
           
	while(q--){
		int t,a,b;
		cin>>t;
   		if(t==1){
   			cin>>a;
   			cout<<s[getp(a)]<<endl;
   		}else{
   			cin>>a>>b;
   			Merge(a,b);
   		}             
   	}	                   
}