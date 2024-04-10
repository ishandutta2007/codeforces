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
ll n,m,k,x,dp[maxn],ans;
vector<int>v;
ll f[maxn],rf[maxn];
ll binpow(ll n, ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)          
		return c*c%mod;
	return c*c%mod*n%mod;
}
bool happy(int x){
	while(x!=0){
		if(x%10==4 || x%10==7)
			x/=10;
		else
			return false;
	}
	return true;
}
ll c(int k ,int n){
	return f[n]*rf[k]%mod*rf[n-k]%mod;
}
void add(ll &x,ll a){
	x+=a;
	if(x>=mod)
		x-=mod;
}
int main(){	
	f[0]=1;
	for(int i=1;i<maxn;i++)
		f[i]=f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;           
		scanf("%d",&x);
		if(happy(x))
			v.pb(x);
		else
			m++;
	}              
	sort(v.begin(),v.end());

	for(int i=0;i<=m;i++)
		dp[i]=c(i,m);
	
	for(int i=0;i<v.size();i++){
		int cnt=1;
		while(i<v.size() && v[i]==v[i+1])
			cnt++,i++;

		for(int j=k;j>=1;j--)
			add(dp[j],dp[j-1]*cnt%mod);
	}
	printf("%I64d",dp[k]);
}