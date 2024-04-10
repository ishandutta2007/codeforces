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
const int maxn=1e5+123,inf=2e9,mod=1e9+7;  
int t,k,dp[maxn],sum[maxn];
int main(){ 
	cin>>t>>k;
	dp[0]=1;
	for(int i=1;i<maxn;i++){
		dp[i]+=dp[i-1]+dp[i-k];
		dp[i]%=mod;
		sum[i]=dp[i]+sum[i-1];
		sum[i]%=mod;
	}
	while(t--){
		int l,r;
		cin>>l>>r;
			cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
	}
}