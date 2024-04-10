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
#define p push 
#define mp make_pair 
#define o cout<<"BUG"<<endl; 
using namespace std;                    
const int maxn=11123,inf=2e9,mod=1e9+7;  
ll n,k,ans[maxn],f[maxn],rf[maxn];
ll c(int k, int n){
	return	f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll get(int mx){
	ll res=1;
	for(int i=2;i*i<=mx;i++){                  
		int cnt=0;
		while(mx%i==0)
			mx/=i,cnt++;
		res*=c(cnt,k+cnt-1);
		res%=mod;
	}
	if(mx!=1)
		res*=c(1,k);
	return res;
}
ll binpow(int n, int p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)
		return c*c%mod;
	return c*c%mod*n%mod;		
}               
int main(){
	f[0]=1;
	for(int i=1;i<maxn;i++)
		f[i]=f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod; 
	cin>>n>>k;

	ll sum=0;
	for(int i=1;i<=n;i++){
		ans[i]=get(i);
		//cout<<endl<<ans[i]<<" ";
		sum=(sum+ans[i])%mod;
		//2 cout<<ans[i]<<" ";
	}
	cout<<sum;
}