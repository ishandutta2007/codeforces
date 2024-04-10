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
const ll maxn=3e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
struct edge{
	int u,v,w;
};                    
bool cmp( edge a, edge b){
	return a.w<b.w;
}
edge a[maxn];
vector<int> t[maxn];
int n,m,dp[maxn],mx;                             
int main(){           
	Bystro
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		t[a[i].w].pb(i);
	}
	for(int w=1;w<maxn;w++){
		set<  pair < int , int > > st;
		for(int	id=0;id<t[w].size();id++){
			int i=t[w][id];
			int u=a[i].u,v=a[i].v;
			st.insert(mp(v,dp[u]+1));
		} 
		for(set< pair< int , int > > ::iterator it=st.begin();it!=st.end();it++)
			dp[(*it).f]=max(dp[(*it).f],(*it).s),mx=max(mx,(*it).s);
	}
	cout<<mx;
}