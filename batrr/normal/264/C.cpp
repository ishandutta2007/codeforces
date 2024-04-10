#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,q,a,b,dp[maxn],mx1,mx2,w[maxn],c[maxn];
void solve(){              
	for(int i=1;i<=n;i++)
		dp[i]=-INF;
	mx1=0,mx2=0;
	dp[0]=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll res=b*w[i];
		
		if(mx1!=c[i])
			res=max(res,dp[mx1]+b*w[i]);
	   	if(mx2!=c[i])
			res=max(res,dp[mx2]+b*w[i]);

	   	res=max(res,dp[c[i]]+a*w[i]);
	   	
	   	dp[c[i]]=max(dp[c[i]],res);
	   	
	   	ans=max(ans,dp[c[i]]);
	   	
	   	if(dp[c[i]]>=dp[mx1] && c[i]!=mx1)
	   		mx2=mx1,mx1=c[i];
	   	else if(dp[c[i]]>=dp[mx2] && c[i]!=mx1)
	   		mx2=c[i];
	}
	cout<<ans<<endl;
}
int main(){              
	Bystro
	cin>>n>>q;         
	
	for(int i=1;i<=n;i++)
		cin>>w[i];
    for(int i=1;i<=n;i++)
		cin>>c[i];
	
	while(q--){
		cin>>a>>b;
		solve();
	}	
}