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
const ll maxn=5e5,inf=2e9,mod=1e9+7; 
ll n,m,k;
ll get(ll g){
	ll res=0;
	for(ll i=1,j=m;i<=n;i++){                         
		 while( j>0 && j*i>g)
		 	j--; 
		 res=res+j;
	}                                           
	return res;

}
int main(){                          
	cin>>n>>m>>k;    
	ll l=1,r=n*m;
	while(l<=r){
		ll M=(l+r)/2;
		if(get(M)>=k)
			r=M-1;
		else
			l=M+1;		
	}
	cout<<l;
}