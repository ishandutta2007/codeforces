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
const ll maxn=1e6+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,a[maxn],t[4*maxn][2];
ll ans;
void up(int v, int tl, int tr , int pos, int val, int k){
	t[v][k]+=val;
	if(tl==tr)
		return;
	int tm=(tl+tr)/2;
	if(pos<=tm)
		up(v+v,tl,tm,pos,val,k);
	else
		up(v+v+1,tm+1,tr,pos,val,k);	
}
ll get(int v, int tl, int tr,  int l, int r, int k){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return t[v][k];
	int tm=(tl+tr)/2;
	return 
	get( v+v,tl,tm,l,min(tm,r),k)
	+
	get(v+v+1,tm+1,tr,max(tm+1,l),r,k)
	;
}
int main(){    
	Bystro
	cin>>n;
	set<int>st;
	map<int,int>mt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	while(!st.empty()){
		mt[*st.rbegin()]=st.size();
		st.erase(*st.rbegin());
	}
	for(int i=1;i<=n;i++)
		a[i]=mt[a[i]];
	for(int i=1;i<=n;i++){
		up(1,1,n,a[i],1,0);
		
		up(1,1,n,a[i],get(1,1,n,a[i]+1,n,0),1);
		
		ans+=get(1,1,n,a[i]+1,n,1); 	
	}
	cout<<ans; 	
}