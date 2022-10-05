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
const ll maxn=1e6+113,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
#define int long long
map< ll ,ll > cnt;
ll n,f[maxn],rf[maxn];
ll binpow(ll n, ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
	return c*c%mod*n%mod;
}
signed main(){
	ios_base:: sync_with_stdio(false);
	f[0]=1;
	for(int i=1;i<maxn;i++)
		f[i]=f[i-1]*i%mod;
	rf[maxn-1]=binpow(f[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	cin>>n;
	ll ans=0,cur=0,mx=-1;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		cnt[x]++;
		mx=max(x,mx);
	}                
	for( map< ll ,ll > :: iterator it=cnt.begin();(*it).f!=mx;it++){
		
		ll a=(*it).f*(*it).s%mod;
		ll b=f[cur]*f[n-cur-1]%mod;
		ll c=f[n]*rf[cur]%mod*rf[n-cur]%mod;
		ans+=a*b%mod*c%mod;
		if(ans>=mod)
			ans-=mod;
		cur+=(*it).s;
		//cout<<ans<<endl;
	}
	cout<<ans;
}