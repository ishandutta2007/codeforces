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
#define op cout<<"BUG"<<endl; 
#define in insert
#define er erase
using namespace std;
const int maxn=1e6+123;
int n,a;
ll ans;
char d;              
vector<ll>r;
vector<ll>g;
vector<ll>b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>d;  
		if(d=='R')
			r.pb(a);
		if(d=='B')
			b.pb(a);
		if(d=='G'){
			g.pb(a);
			b.pb(a);
			r.pb(a);  	
		}
	}                    
	for(int i=1;i<r.size();i++)
		ans+=r[i]-r[i-1];     
	for(int i=1;i<b.size();i++)
		ans+=b[i]-b[i-1];
	if(g.size()==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<g.size();i++)
		ans+=g[i]-g[i-1];
	int ib=0,ir=0; 
	while(b[ib]!=g[0])
		ib++;
	while(r[ir]!=g[0])
		ir++;
	for(int i=1;i<g.size();i++){
		ll p1=g[i-1],p2=g[i],mx1=0,mx2=0;      
		for(;r[ir]!=p2;ir++)
			mx1=max(mx1,r[ir+1]-r[ir]);
		for(;b[ib]!=p2;ib++)
			mx2=max(mx2,b[ib+1]-b[ib]);
		ans-=max(p2-p1,mx1+mx2);;
	}
	cout<<ans;
}