#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const ll maxn=11e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
pair<ll,ll> T[25];
bool rev[25];
int n,a[maxn],q,x,pn;
void build(int v, int tl, int tr, int p){
	if(tl==tr)
		return;
	int tm=(tl+tr)>>1;
	ll val;          
	
	build(v+v,tl,tm,p-1);
	build(v+v+1,tm+1,tr,p-1);
	
	for(int i=tl,j=tm+1;i<=tm;i++){
		while(j<=tr && a[j]<a[i])
			j++;
		T[p].f+=j-tm-1;
	}
	
	for(int i=tl,j=tm+1;j<=tr;j++){
		while(i<=tm && a[i]<a[j])
			i++;
		T[p].s+=i-tl;
	}
	
	vector<int>vec;
	int i=tl,j=tm+1;
	while(i<=tm || j<=tr){
		if(i<=tm && j<=tr){
			if(a[i]<a[j])    
				vec.pb(a[i++]);
			else
				vec.pb(a[j++]);
		}else{
			if(i<=tm)
				vec.pb(a[i++]);
			else
				vec.pb(a[j++]);
		}
	}
	for(int i=0;i<vec.size();i++)
		a[i+tl]=vec[i];
}   
int main(){              
	scanf("%d",&pn);
	
	n=(1<<pn);
	for(int i=1;i<=n;i++)
	 	scanf("%d",&a[i]);
	
	build(1,1,n,pn);
	
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
	    rev[x]=!rev[x];
	    pair < ll, ll > ans=mp(0,0);
	    for(int p=0;p<=pn;p++){
	    	ans.f+=T[p].f;
	    	ans.s+=T[p].s;
	    	if(rev[p])
	    		swap(ans.f,ans.s);
	    }

		printf("%I64d\n",ans.f);
	}	
}