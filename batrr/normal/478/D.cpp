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
const ll maxn=1e6,inf=2e9,mod=1e9+7; 
int r,g,mxh,dp[maxn][2];
int main(){         
	cin>>r>>g;
	dp[0][0]=1;
	ll ans,lastans;
	for(int h=1;h>0;h++){
		ans=0;
		int f=h%2,s=1-h%2;
		for(int i=0;i<=h*(h+1)/2;i++){
			dp[i][f]=dp[i][s];
			if(i-h>=0)
				dp[i][f]+=dp[i-h][s];
			dp[i][f]%=mod;
			if(i<=r && h*(h+1)/2-i<=g){
				ans+=dp[i][f];
				ans%=mod;
			}
		}
		if(ans==0){
			cout<<lastans;
			return 0;
		}
		lastans=ans;
	}                
}