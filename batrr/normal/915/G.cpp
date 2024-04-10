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
const ll maxn=2e6+1,inf=2e9,mod=1e9+7;
ll n,k,bp[maxn],dp[maxn],ans,sum;
ll binpow(ll n,ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);	
	if(p%2==0)         
		return c*c%mod;
	return c*c%mod*n%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		bp[i]=binpow(i,n);
	for(int i=1;i<=k;i++){
		dp[i]=(dp[i]+bp[i]-bp[i-1])%mod;
		if(dp[i]<0)	
			dp[i]+=mod;
		sum=(sum+dp[i])%mod;
		ans=(ans+(sum^i))%mod;
		//cout<<i<<" "<<sum<<endl;
		for(int j=2;j*i<=k;j++)
			dp[j*i]=(dp[j*i]-dp[i]+mod)%mod;
	}
	cout<<ans;
}