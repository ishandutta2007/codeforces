
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
const ll maxn=2e5+1,inf=2e9,mod=1e9+7; 
ll n,k,ans,f[1500],rf[1500],dp[1500];
string s;
int calc(int g){
	int res=0;
	while(g!=0)
		res+=g%2,g/=2;
	return res;
}
ll c(int n, int k){
	if(k>n || k<0)
		return 0;
	return f[n]*rf[k]%mod*rf[n-k]%mod;
}
int get(int cnt){                    
	ll res=0,d=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			d++;
	if(d==cnt)
		res++;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			res+=c(s.size()-i-1,cnt--);
			res%=mod;            
		}	                  
	}
	return res;		
}
ll binpow(ll n, int p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
		return c*c%mod*n%mod;;	
}
int main(){         
	f[0]=1;
	for(int i=1;i<1500;i++)
		f[i]=f[i-1]*i%mod;
	rf[1499]=binpow(f[1499],mod-2);
	for(int i=1498;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	cin>>s;
	cin>>k;
	dp[1]=0;
	for(int i=2;i<1001;i++){
		dp[i]=dp[calc(i)]+1;
};
	
	for(int i=1;i<1001;i++){	
        if(dp[i]==k-1){
			ans+=get(i);
			ans%=mod;
		}
	} if(k==1)
 ans--;
	if(k==0)
		ans++;
	cout<<ans;
}