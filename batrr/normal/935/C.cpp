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

using namespace std;                    

const ll maxn=5500,N=400,inf=2e18,mod=1e9+7;
const ld eps=1e-12;
ld r,xa,ya,xb,yb;
ld dis( ld xa,ld ya,ld xb,ld yb){
	return sqrtl( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) ) ;
}
int main(){    
	cin>>r>>xa>>ya>>xb>>yb;
	cout<<fixed<<setprecision(20);
	
	if(xa==xb && ya==yb){
		cout<<xa+r/2 <<" "<<ya<<" "<<r/2<<endl;
		return 0;
	}                       
	if( dis(xa,ya,xb,yb) > r-eps){
		cout<<xa<<" "<<ya<<" "<<r;
		return 0;
	}                     
	
	ld d=dis(xa,ya,xb,yb);
	cout<< ( (xa-xb)*(d+r)/d+xb + xb )/2<<" ";
	cout<< ( (ya-yb)*(d+r)/d+yb + yb )/2 <<" ";
	cout<<(d+r)/2;
}