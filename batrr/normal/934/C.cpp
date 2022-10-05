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
const ll maxn=1e5+123,inf=1e9,INF=1e18,N=1e6;
using namespace std;
ll ans,n,a[maxn],C[50],c[50],dp[maxn];       
int main(){
	//IO           
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		C[a[i]]++;
	}
	dp[0]=C[2];
	for(int l=1;l<=n;l++){
		ll cur=0;	
		for(int r=l;r<=n;r++){
			if(a[r]==2)
				cur--;
			else
				cur++;
			cur=max(cur,dp[l-1]);			
			ans=max(ans,cur);
		}
		c[a[l]]++;
		dp[l]=c[1]+C[2]-c[2];		
	}
	cout<<ans;
}