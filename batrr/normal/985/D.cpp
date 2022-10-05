// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6,inf=1e8,mod=1e9+7,block=200,N=1e6;
ll n,h;
ll sum(ll l,ll r){
	if(l>r)
		return 0;
	return (l+r)*(r-l+1)/2;
}
ll get2(ll len){
	if(len%2==0)              
		return sum(1,len/2)*2;
	return sum(1,len/2)*2+len/2+1;
}
ll get(ll m){
	if(m<=h)
		return sum(1,m);
	else{
		ll l=m-h;
		return sum(1,h)+get2(l-1)+l*h;
	}
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif      
	cin>>n>>h;
	
	ll l=1,r=2e9+123;
	while(l<=r){
		ll m=(l+r)/2;
		if(  get(m) < n )
			l=m+1;
		else
			r=m-1;
	}
	//for(int i=0;i<10;i++)
	//	cout<<i<<":"<<get(i)<<endl;
	//cout<<get(l+1)<<endl;
	cout<<l;
}