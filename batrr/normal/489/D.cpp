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
const ll maxn=5e5,inf=2e9,mod=1e9+7; 
vector<int>g[maxn];
ll n,ans,m,cnt[maxn];
void dfs(int v, int len){
	if(len==2){
		cnt[v]++;
		return;
	}
	for(int i=0;i<g[v].size();i++)
		dfs(g[v][i],len+1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v,to;
		cin>>v>>to;
		g[v].pb(to);
	}                         
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cnt[j]=0;
		dfs(i,0);
		for(int j=1;j<=m;j++){
			if(j!=i && cnt[j]>=2){
				ans+=cnt[j]*(cnt[j]-1)/2;
			}
		}
	} 
	cout<<ans;
}