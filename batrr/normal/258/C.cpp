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
const ll maxn=1e5+123,mod=1e9+7;
ll n,a[maxn],ans,pre[maxn];
ll get(int l, int r){
	return pre[r]-pre[l-1];
}
ll binpow(ll n, ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
		return c*c%mod*n%mod;
}       
int main(){	
	Bystro
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[a[i]]++;
	}

	for(int i=1;i<maxn;i++)
		pre[i]+=pre[i-1];

	sort(a+1,a+1+n);
	for(int x=1;x<=a[n];x++){
		
		vector<int>v;
		
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				v.pb(i);
				if(i*i!=x)
					v.pb(x/i);	
			}
		}
		
		sort(v.begin(),v.end());
		ll res=1;
		for(int i=v.size()-2;i>=0;i--)
			res=res*binpow( i+1 , get( v[i],v[i+1]-1) )%mod; 	
		
		/*
		while(a[i]<x){
			while(v[j]<=a[i])
				j++;
			res=res*j%mod;
			i++;		
		}
		*/
		res=res*( binpow(v.size(),get(x,maxn-1) )-binpow(v.size()-1, get(x,maxn-1) ) + mod )%mod;
		//cout<<x<<" "<<res<<endl;
		ans+=res;
	}      
	cout<<ans%mod;
}