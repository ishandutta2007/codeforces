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
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=2e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
ll n,x,q;
ll get(ll x , ll n){             /*
	cout<<x<<" "<<n<<endl;     */
	if(x%2==1)
		return	(x+1)/2;
	if(n%2==0)
		return get(x/2,n/2)+n/2;
	
	if(x==2)
		return get(n/2,n/2)+n/2+1;
	
	return get(x/2-1,n/2)+n/2+1;
		
}
int main(){        
	cin>>n>>q;
	while(q--){
		cin>>x;
		cout<<get(x,n)<<endl;
	}
}