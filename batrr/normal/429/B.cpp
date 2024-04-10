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
const ll maxn=1002,inf=2e9,mod=1e9+7; 
int n,m,dp[maxn][maxn][4],a[maxn][maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
     		cin>>a[i][j];                 
   	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int res=0;                    
			if(i!=1)
				res=max(res,dp[i-1][j][0]);
			if(j!=1)
				res=max(res,dp[i][j-1][0]);
			dp[i][j][0]=res+a[i][j];
		}
	}

   	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			int res=0;                    
			if(i!=1)
				res=max(res,dp[i-1][j][3]);
			if(j!=m)
				res=max(res,dp[i][j+1][3]);
			dp[i][j][3]=res+a[i][j];
		}
	}

	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			int res=0;                    
			if(i!=n)
				res=max(res,dp[i+1][j][2]);
			if(j!=1)
				res=max(res,dp[i][j-1][2]);
			dp[i][j][2]=res+a[i][j];
		}
	}
	                         
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			int res=0;                    
			if(i!=n)
				res=max(res,dp[i+1][j][1]);
			if(j!=m)                          
				res=max(res,dp[i][j+1][1]);
			dp[i][j][1]=res+a[i][j];
		}
	}                 /*     
	int q ;                            //    ****************
	while(cin>>q){                       //  *1            2* 
		for(int i=1;i<=n;i++){            // *              *
			for(int j=1;j<=m;j++)          // 3            4
				cout<<dp[i][j][q]<<" ";
			cout<<endl;
		}
	}                   */     
	ll ans=-4e18;
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){                                                            
			ans=max(ans,1ll+dp[i-1][j][0]+dp[i+1][j][1]+dp[i][j-1][2]+dp[i][j+1][3]);
        	ans=max(ans,1ll+dp[i][j-1][0]+dp[i][j+1][1]+dp[i+1][j][2]+dp[i-1][j][3]);
        }
	}
   	cout<<ans-1;
}