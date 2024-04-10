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
#define op cout<<"BUG"<<endl; 
#define in insert
#define er erase
using namespace std;
const int maxn=5123,inf=1e9,mod=1e9+7; 
ll n,dp[maxn][maxn];
char d[maxn];
int main(){ 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		if(d[i-1]=='f'){
			for(int j=0;j<=n;j++)
				dp[i][j+1]=dp[i-1][j];
		}else{
			ll sum=0;
			for(int j=n;j>0;j--){
				sum+=dp[i-1][j]%mod;
				sum=sum%mod;
				dp[i][j]=sum;
			}
		}
	}
	ll ans=0;               /*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}                     */
	for(int i=0;i<=n;i++)
		ans=(ans+dp[n][i])%mod;
	cout<<ans;
}