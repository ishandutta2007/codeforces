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
#define Bystro ios_base::sync_with_stdio(0);
 
using namespace std;                    
const ll maxn=5e5+123,N=2e5,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
ll k,d,s;
ld get(ll t){
	ld res=0;
	res+=t/(k+d)*d;
	t%=k+d;
	if(t>2*k)
		res+=t-2*k,t=2*k;
	res+=t/2.0;
	return res;	
}
int main(){      
  	cin>>k>>d>>s;
    if(k%d==0)
    	d=k;
    else
    	d=(k+d-1)/d*d;
    s*=2;
    cout<<fixed<<get(s);
    return 0;
}