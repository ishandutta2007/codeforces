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
                    
#define nm "array" 
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
const ll maxn=5e3+13,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
ll dp[maxn][maxn],n,k;
ll binpow(ll n ,ll p){
    if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)         
		return c*c%mod;
	return c*c%mod*n%mod;
}
int main(){          
	//IO                 
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j-1]*(n-j+1)+j*dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	ll res=0;
	for(int i=1;i<=min(n,k);i++)
		res=(res+dp[k][i]*binpow(2,n-i))%mod;
	cout<<res;
}