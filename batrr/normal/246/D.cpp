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
vector<int>g[maxn];
int n,m,c[maxn],ans[maxn];
bool used[maxn];
set < pair < int, int > > st;
void dfs(int v){
	//cout<<v<<" ";
	used[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(c[to]!=c[v] && st.find(mp(c[v],c[to]))==st.end()){
			ans[c[v]]++;
			st.insert(mp(c[v],c[to]));
		}
		if(used[to]==false)
			dfs(to);
	}
}
int main(){ 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(ans[c[i]]==0)
			ans[c[i]]++;
	}
	for(int i=0;i<m;i++){
		int v,u;
		cin>>v>>u; 
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i=1;i<=n;i++)
		if(used[i]==0)
			dfs(i);   
	int res=0;
	for(int i=1;i<maxn;i++){
		if(ans[res]<ans[i]){
			res=i;
		}
	}
	cout<<res;
}