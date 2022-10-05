#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring> 
#include <string> 
#include <string.h>
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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=2e5+123,N=5010,inf=1e9,mod=1e9+7,INF=1e18;
const ld eps=1e-12,PI=3.141592653589793238462643383279;  
vector<int>g[maxn];
int n,ans,cnt[maxn];
void dfs(int v,int lvl){
	cnt[lvl]++;
	for(int i=0;i<g[v].size();i++)
		dfs(g[v][i],lvl+1);
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int v;
		cin>>v;
		g[v].pb(i);
	}
	dfs(1,1);
	for(int i=0;i<maxn;i++)
		ans+=cnt[i]%2;
	cout<<ans;
}