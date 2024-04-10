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
const ll maxn=1e5+13,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
ll t,ans,x,n,m;
void solve(){
	if(ans==0){
		cout<<"1 1"<<endl;
		return ;
	}
	for(int i=1;i*i<=ans;i++){
		if(ans%i==0){ 
			ll a=i,b=ans/i;
			if((b-a)%2==1)
				continue;
			ll x=abs(b-a)/2;
			if(x==0)
				continue;
			ll n=(b+a)/2;
			for(int d=-5;d<=5;d++){
				ll m=n/x+d;
				if(m<=0 || m>n || n/m!=x)
					continue;
				//cout<<a<<" "<<b<<" "<<x<<endl;
				cout<<n<<" "<<m<<endl;
				return;
			}
		}
	}
	cout<<-1<<endl;;
}
int main(){                              
	cin>>t;
	while(t--){
		cin>>ans;
		solve();
	}
}