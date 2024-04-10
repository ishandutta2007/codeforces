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
const ll maxn=2e5+132;
vector< int >g[maxn];
struct edge{
	int u,v,c,id;
};
edge a[maxn];
int n,m,ans[maxn],f[maxn],used[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].v>>a[i].u>>a[i].c;
		
		f[a[i].u]+=a[i].c;
        f[a[i].v]+=a[i].c;
        a[i].id=i;
              
        g[a[i].u].pb(i);
        g[a[i].v].pb(i);
	} 
	f[1]=0;
	for(int i=2;i<n;i++)
		f[i]/=2;
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0;i<g[v].size();i++){
			int id=g[v][i],to=a[id].v+a[id].u-v;
			if(used[id])
				continue;

			used[id]=1;
			if(v==a[id].v)
				ans[id]=0;
			else
				ans[id]=1;
			f[to]-=a[id].c;
			if(f[to]==0)
				q.push(to);	
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
}