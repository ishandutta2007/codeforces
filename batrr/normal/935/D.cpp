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

using namespace std;                    

const ll maxn=2e5+123,N=400,inf=2e18,mod=1e9+7;
const ld eps=1e-12;
ll n,a[maxn],b[maxn],m,cur,all,good;
ll f[maxn],rf[maxn];
ll pre1[maxn],pre2[maxn];
ll binpow(ll n, ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
	return c*c%mod*n%mod;
}                        
ll get1(int l ,int r){
	ll res=pre1[r]-pre1[l-1];
	if(l>r)
		res=0;
	return binpow(m,res);
}

ll get2(int l ,int r){
	ll res=pre2[r]-pre2[l-1];
	if(l>r)
		res=0;
	return binpow(m,res);
}
int main(){
//	IO
	ios_base::sync_with_stdio( false);
  
	f[0]=1;
	for(int i=1;i<maxn;i++)
		f[i]=f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	cur=1;
	cin>>n>>m;    
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre1[i]=pre1[i-1]+( a[i]==0);
	}                                
	for(int i=1;i<=n;i++){
		cin>>b[i];
		pre2[i]=pre2[i-1]+( b[i]==0);
	}
	all=get1(1,n)*get2(1,n)%mod;
	for(int i=1;i<=n;i++){
		if(a[i]==0 && b[i]!=0){
			good+= get2(i,n)    *get1(i+1,n)%mod *(m-b[i])%mod *cur %mod;
			good%=mod;
		}
		if(a[i]!=0 && b[i]==0){
			good+=  get2(i+1,n) *get1(i,n)%mod   *(a[i]-1)%mod  *cur %mod;
			good%=mod;
		}
		if(a[i]!=0 && b[i]!=0){
			if(a[i]==b[i])
				continue;
			if(a[i]>b[i]){
				good+=   get2(i+1,n) *get1(i+1,n)%mod  *cur %mod;
				good%=mod;
			}
			break;
		}
		if(a[i]==0 && b[i]==0){
			good+= f[m] *rf[2]%mod *rf[m-2]%mod *get2(i+1,n)%mod *get1(i+1,n)%mod *cur%mod; 
			cur*=m;
			cur%=mod;
			good%=mod;
		}
	}
	//cout<<good<<" "<<all<<endl;
	cout<<good*binpow(all,mod-2)%mod;
}