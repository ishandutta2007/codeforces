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
const ll maxn=1e5+12,inf=2e9,mod=1e8; 
vector<int>g[maxn],c;
int n,m,t[maxn];
pair<int,int> ban;
bool used[maxn],end;
void dfs(int v){
	if(t[v]==1){
		c.pb(v);
		return ;
	}
	if(t[v]==2)
		return;
	t[v]=1;
	used[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		dfs(to);   
		if(!c.empty()){
			if(c[0]!=c[c.size()-1] || c.size()==1)
				c.pb(v);   
			return;
		}
	}
	t[v]=2;
}
bool dfs2(int v){
	if(t[v]==1)
		return false;
	if(t[v]==2)
		return true;
	t[v]=1;
	bool res=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(mp(v,to)==ban)
			continue;
		res=(res & dfs2(to));
	}
	t[v]=2;
	return res;
}
int main(){          	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v,to;
		cin>>v>>to;
		g[v].pb(to);
	}
	for(int i=1;i<=n;i++){
		if(!used[i])
			dfs(i);
		if(!c.empty())
			break;
	}
	if(c.empty()){
		cout<<"YES";
		return 0;
	}
	reverse(c.begin(),c.end());
	
	for(int i=0;i<c.size()-1;i++){
		ban=mp(c[i],c[i+1]);
		//cout<<c[i]<<" "<<c[i+1]<<endl;
		for(int j=1;j<=n;j++)
			used[j]=0,t[j]=0;
		bool res=1;
		for(int j=1;j<=n;j++)
			if(!used[j])
				res= ( res & dfs2(j) );
		if(res){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}