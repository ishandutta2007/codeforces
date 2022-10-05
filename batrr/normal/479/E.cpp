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
int n,a,b,k,dp[5100][5100],up[5100][5100];
void add( int &a,int x){
	a+=x;
	if(a>=mod)
		a-=mod;
	if(a<0)
		a+=mod;
}
int main(){                                                                      
	cin>>n>>a>>b;
	up[0][a]++;
	up[0][a+1]--;
	for(k=0;k<=5000;k++){
		for(int i=1;i<=n;i++){
			dp[k][i]=(dp[k][i-1]+up[k][i])%mod;
			
			int mx=abs(i-b)-1;
			
			add(up[k+1][max(1,i-mx)], dp[k][i]);
			add(up[k+1][min(n,i+mx)+1],-dp[k][i]);
			
			add(up[k+1][i],-dp[k][i]);
			add(up[k+1][i+1],+dp[k][i]);
		}
	}          
	ll ans=0;
	cin>>k;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[k][i])%mod;
	cout<<ans;
}