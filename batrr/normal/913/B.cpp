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
const int maxn=1e6+1,mod=1e9+7,M=3600*12;
const ll inf=1e18;
const ld eps=1e-6;
vector<int>g[1500];
int n;
int dfs(int v){
	int cnt=0;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		cnt+=dfs(to);
	}
	if(cnt<3 && g[v].size()>0)
		return -123123;		
	if(g[v].size()==0)
		return 1;
	else
		return 0;
	
}
int main(){   
	cin>>n;
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		g[a].pb(i);
	}   
	if(dfs(1)==0){
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0; 
}