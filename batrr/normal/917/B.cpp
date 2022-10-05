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
const ll maxn=1e5+123,inf=2e9,mod=1e9+7;  
vector< pair< int , int> > g[maxn];
ll ans,win[200][200][200],n,m;
bool used[200][200][200];
void dfs(int v,int u,int k){
	if(used[v][u][k])
		return;
	used[v][u][k]=1;
	int res=2;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i].f;
		if(g[v][i].s>=k){
			dfs(u,to,g[v][i].s);
			if(win[u][to][g[v][i].s]==2)
				res=1;
		}
	}
	win[v][u][k]=res;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		char c;
		cin>>u>>v>>c;
		g[u].pb(mp(v,(int)(c-'a')));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!used[i][j][0]){
				dfs(i,j,0);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(win[i][j][0]==1)
				cout<<'A';
			else
				cout<<'B';
		cout<<endl;	
	}
}