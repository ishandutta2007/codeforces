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
const ll maxn=3e5+1,inf=2e9,mod=1e9+7;
int ans,n,q,l,r,k;
set<pair<int,int> > st;
set<pair<int,int> >:: iterator it;
int main(){
    ios_base::sync_with_stdio(false);
	cin>>n>>q;
	ans=n;
	while(q--){                       
	    cin>>l>>r>>k;
		while(true){
			it=st.lower_bound(mp(l,0));
			if(it==st.end())
				break;
			int bl=(*it).s,br=(*it).f;
			if(bl>r)
				break;
			ans+=br-bl+1;
			st.erase(mp(br,bl));
			if(br>r){
				ans-=br-r;
				st.insert(mp(br,r+1));
			}
			if(bl<l){
				ans-=l-bl;
				st.insert(mp(l-1,bl));
			}	
		}
		if(k==1){
			ans-=r-l+1;
			st.insert(mp(r,l));
		}               
		cout<<ans<<endl;
	}                   
}