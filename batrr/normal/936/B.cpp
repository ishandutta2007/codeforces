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
const ll maxn=5e5+123,N=2e5,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
vector<int> g[maxn];
int n,m,x,st,c[maxn];
bool dp[maxn][3],u;
vector<int>ans;
void rec(int v, int p){
	if(dp[v][p])
		return;

	dp[v][p]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		rec(to,3-p);
		if(u){
			ans.pb(v);
			return;
		}
	}
	if(p==2 && g[v].size()==0){
		ans.pb(v);
		u=1;
	}
	return;
}
void dfs(int v){
	if(c[v]==2)
		return;
	if(c[v]==1){
		cout<<"Draw";
		exit(0);
	}
	c[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		dfs(to);
	}
	c[v]=2;  
}
int main(){
	cin>>n>>m;
	for(int i=1,j;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>j;
			g[i].pb(j);
		}		
	}
	cin>>st;
	rec(st,1);
	if(u){
		cout<<"Win"<<endl;
		for(int i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<" ";
		return 0;
	}
	dfs(st);
	cout<<"Lose";
	return 0;
}