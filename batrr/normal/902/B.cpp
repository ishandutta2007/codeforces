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
  
#define nm "i" 
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
#define op cout<<"BUG"<<endl; 
#define in insert
#define er erase
using namespace std;
const int maxn=1e6;
vector<int>g[maxn];
ll n,ans,c[maxn],cn[maxn];
bool used[maxn];
void paint(int v,int color,int p){
	for(int i=0;i<g[v].size();i++){
		int t=g[v][i];
		if(t!=p){
			cn[t]=color;
			paint(t,color,v);
		}
	}	
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int q,w;
		cin>>w;
		q=i+2; 
		g[q].pb(w);
		g[w].pb(q);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];	
	queue<pair<int ,int > > q;
	q.push(mp(1,0));
	while(!q.empty()){
		int v=q.front().f,p=q.front().s;
		q.pop();           
		if(c[v]!=cn[v]){
		    ans++;
			paint(v,c[v],p);
		}
		for(int i=0;i<g[v].size();i++){
			int t=g[v][i];
			if(t!=p){
				q.push(mp(t,v));
			}	
		}
	}
	cout<<ans;
}