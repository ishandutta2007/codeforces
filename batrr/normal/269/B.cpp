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
const ll maxn=1e6+1,inf=2e9,mod=1e9+7; 
vector < pair < ld , int > > v;
int n,m,ans,dp[5001];
int main(){     
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		ld x;
		cin>>a>>x;
		v.pb(mp(x,a));
	}
	for(int i=0;i<n;i++)
		for(int j=i;j>=0;j--)
			if(v[i].s>=v[j].s)
				dp[i]=max(dp[i],dp[j]+1),ans=max(ans,dp[i]);	
   cout<<n-ans;
}