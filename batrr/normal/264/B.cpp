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
const ll maxn=1e6+12,inf=2e9,mod=1e8; 
int n,a[maxn],dp[maxn],ans;
int main(){        
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>v;
		int res=0;
		//cout<<endl<<a[i]<<":";
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				v.pb(j);
				res=max(res,dp[j]);
				while(a[i]%j==0)
					a[i]/=j;
			}
		}
		if(a[i]!=1){
			v.pb(a[i]);
			res=max(res,dp[a[i]]);
			a[i]/=a[i];
		}	
		for(int j=0;j<v.size();j++){
			dp[v[j]]=res+1;
		//	cout<<v[j]<<" ";
		}
		ans=max(ans,res+1);
	}
	cout<<ans;
}