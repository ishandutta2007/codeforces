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
  
#define nm "gcd" 
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
const ll maxn=2e5+123,N=2e5,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
int n,a[maxn],dp[maxn],k;                
ll get( int l1 , int r1 ,int l2 , int r2){
	if(r1<l2)
		return 0;                             
	return r1-l2+1;	
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0)
			dp[i]=min(n-i,k)+min(i-1,k)+1;
		else
			dp[i]=min(n-i,k)+min(i-1,k)+1+dp[a[i]]-get(max(1,a[i]-k),min(n,a[i]+k),max(1,i-k),min(n,i+k));
		cout<<dp[i]<<" ";
	}
}