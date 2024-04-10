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
const ll maxn=1e6+113,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;              
vector <int > g[maxn];
string s,t;
int n;
vector< pair < int , int > > ans;
bool used[maxn];
void dfs(int v){
	used[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(used[to]==0){
			dfs(to);
			ans.pb(mp(v,to));
		}
	}
}
int main(){                             
	cin>>n;     
	cin>>s>>t;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){                  
			g[s[i]].pb(t[i]);
			g[t[i]].pb(s[i]);
		}                  
	}
	for(int i=1;i<=1000;i++){
		if(used[i]==0){
			dfs(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		printf("%c %c\n",ans[i].f,ans[i].s);
}