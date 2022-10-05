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
ll p,k;
bool used[maxn];       
vector<ll>ans;
int main(){
	cin>>p>>k;
	ll last=p,g=1e7;
	ans.pb(last);
	while(g--){
		if(g==1){
			cout<<-1;
			return 0;
		}
        ll cur=(k-last)/k+2;
        while(cur*k+last>=k)
        	cur--;
        if(cur==0)
        	break;
        ans.pb(cur);
    	last=cur; 
	}
	reverse(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>0;i--)      
    	printf("%lld ",ans[i]+ans[i-1]*k);
    printf("%lld",ans[0]);  
}