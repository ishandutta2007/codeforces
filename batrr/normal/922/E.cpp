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
const ll maxn=1e3+123,N=1e3,inf=1e18+1,mod=1e9+7;   
ll n,mx,b,cur,x,ans;  
ll dp[maxn][maxn*20],c[maxn],cost[maxn];
int main(){
    ios_base:: sync_with_stdio(false);
    cin>>n>>mx>>b>>x;
    for(int i=1;i<=n;i++)
    	cin>>c[i];	
    for(int i=1;i<=n;i++)
    	cin>>cost[i];	
    for(int i=0;i<maxn;i++)
    	for(int j=0;j<20*maxn;j++)
    		dp[i][j]=-inf;
    dp[1][0]=mx;
    ll cnt=0;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=cnt;j++){
    		if(dp[i][j]==-inf)
    			continue;
    		dp[i][j]=min(dp[i][j],mx+j*b);
    		for(int q=0;q<=c[i] && dp[i][j]-q*cost[i]>=0;q++){
    			dp[i+1][j+q]=max(dp[i+1][j+q],dp[i][j]-q*cost[i]+x);
    			ans=max(ans,0ll+j+q);
    		}
    	}
    	cnt+=c[i];
    }
    cout<<ans;
}