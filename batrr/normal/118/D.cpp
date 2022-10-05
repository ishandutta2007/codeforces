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
const ll maxn=5e5,inf=2e9,mod=1e8; 
int n1,n2,k1,k2;
ll dp[150][150][11][11];
int main(){             
	cin>>n1>>n2;        
	cin>>k1>>k2;     
	dp[1][0][1][0]=1;
	dp[0][1][0][1]=1;
	for(int sum=1;sum<n1+n2;sum++){
		for(int i1=sum-min(sum,n2),i2=min(sum,n2);i1<=n1 && i2>=0;i1++,i2--){
			for(int j1=1;j1<=k1;j1++){
				dp[i1][i2+1][0][1]+=dp[i1][i2][j1][0];	
				dp[i1][i2+1][0][1]%=mod;	
				if(j1+1<=k1){                                
					dp[i1+1][i2][j1+1][0]+=dp[i1][i2][j1][0];
					dp[i1+1][i2][j1+1][0]%=mod;
				}	
			}
			for(int j2=0;j2<=k2;j2++){
				dp[i1+1][i2][1][0]+=dp[i1][i2][0][j2];	
				dp[i1+1][i2][1][0]%=mod;	
				if(j2+1<=k2){
					dp[i1][i2+1][0][j2+1]+=dp[i1][i2][0][j2];	
					dp[i1][i2+1][0][j2+1]%=mod;
				}
			}
		}
	}
	ll ans=0;                          
	for(int i=1;i<=k1;i++)
		ans=(ans+dp[n1][n2][i][0])%mod;
	for(int i=1;i<=k2;i++)
		ans=(ans+dp[n1][n2][0][i])%mod;
	cout<<ans;
}