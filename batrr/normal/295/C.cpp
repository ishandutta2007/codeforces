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
const ll maxn=2e5+132,mod=1e9+7;
ll n,m,k,dp[51][51][250],c[1000][1000];
int main(){
	for(int i=0;i<1000;i++)
		c[0][i]=1;
	for(int i=1;i<1000;i++)
		for(int j=1;j<1000;j++)
			c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
	                    
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==100)
			m++;
	}
	n-=m;           
	dp[n][m][0]=1;

	for(int cntt=0;cntt<250;cntt++){
		/*                 
		cout<<cntt<<endl;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(dp[i][j][cntt]!=0)
					cout<<i<<" "<<j<<endl;
			}
		}
		*/
		if(dp[0][0][cntt]!=0){
			cout<<cntt<<endl;
			cout<<dp[0][0][cntt]<<endl;
	    	return 0;
		}
		if(cntt%2==0){
			for(int i=0;i<=n;i++){
				for(int j=0;j<=m;j++){
					for(int x=0;x<=i;x++){
						for(int y=0;y<=j;y++){
							if(x+y>0 && x*50+y*100<=k){
								dp[i-x][j-y][cntt+1]+=dp[i][j][cntt]* c[x][i] * c[y][j]%mod;
								dp[i-x][j-y][cntt+1]%=mod;	
							}
						}
					} 	
				}
			}
		}else{
		    for(int i=0;i<=n;i++){
				for(int j=0;j<=m;j++){
					for(int x=0;x<=n-i;x++){
						for(int y=0;y<=m-j;y++){
							if(x+y>0 && x*50+y*100<=k){
								dp[i+x][j+y][cntt+1]+=dp[i][j][cntt]* c[x][n-i] * c[y][m-j]%mod;	
								dp[i+x][j+y][cntt+1]%=mod;	
							}
						}
					} 	
				}
			}
		}                   
	}
	cout<<-1<<endl<<0;		
}