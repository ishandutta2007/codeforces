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
const ll maxn=11e5+123,g=1e4+12,inf=1e9,INF=1e18,block=1000,mod=INF+1;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,l,r,mx[61];
ll cntmod;
ll binmult(ll a,ll b){
	if(b==0)
		return 0;
	ll c=binmult(a,b/2);
	cntmod+=(c+c)/mod;
	c=(c+c)%mod;
	if(b%2==0)
		return c;
	cntmod+=(c+a)/mod;
	return (c+a)%mod;	
}        
ll binpow(ll n,ll p){
    if(p==0)
        return 1;
    ll c=binpow(n,p/2);
    c=binmult(c,c);
    if(p%2==0)
        return c;
    return binmult(c,n);
}

ll binpow1(ll n,ll p){
    if(p==0)
        return 1;
    ll c=binpow1(n,p/2);
    if(p%2==0)
        return c*c;
    return c*c*n;
}
ll getm(ll n, ll p){
	int l=0,r=mx[p];
	while(l<=r){
		int m=(l+r)/2;
		if(binpow1(m,p)<=n)
			l=m+1;
		else
			r=m-1;
	}
	return l-1;
}
ll get(ll n){
	if(n==0)
		return 0;
	ll res=0,cnt[61];
	for(int i=60;i>1;i--){
	    cnt[i]=getm(n,i);
	    
	    for(int j=i+i;j<=60;j+=i)
			cnt[i]-=cnt[j];
		
		cnt[i]--;
	
		res+=cnt[i];
	}
	return res+1;
}            
ll getmx(int p){
	ll l=0,r=1e9+123;
	while(l<=r){
		ll m=(l+r)/2;
		cntmod=0;
		
		binpow(m,p);
		
		if(cntmod==0)
			l=m+1;
		else
			r=m-1;
	}
	return l-1;
}
int main(){                                                  
    for(int i=2;i<=60;i++)
		mx[i]=getmx(i);
	Bystro;
    cin>>n;
    while(cin>>l>>r)
		cout<<get(r)-get(l-1)<<endl;
}