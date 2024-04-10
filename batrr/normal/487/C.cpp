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
const ll maxn=1e5+123;
ll n,a[maxn],cur,mod;
bool used[maxn];
ll binpow(ll n, ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
		return c*c%mod*n%mod;
}
bool prime(ll x){
	for(int i=2;i<x;i++)
		if(x%i==0)
			return false;
	return true;
}    
int main(){	
	Bystro
	cin>>n;
	mod=n;
	if(n<=4){
		cout<<"YES"<<endl;
		cout<<1<<endl;
	    
	    if(n==2)
	    	cout<<2<<endl;	
	    if(n==3)
	    	cout<<2<<endl<<3<<endl;	
	    if(n>=4)
	    	cout<<3<<endl<<2<<endl<<4<<endl;	
	   
	    return 0;
	}
	if( !prime(n) ){
		cout<<"NO";
		return 0;
	}       
	
	a[1]=1;                                            
	for(int i=2;i<=n;i++)
		a[i]=(1+binpow(i-1,n-2))%n;
	
	a[n]=n;
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
}