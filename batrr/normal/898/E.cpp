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
  
#define nm "word" 
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
const int maxn=1e6;
ll n,a[maxn],cnt,ans,mn[maxn];
vector<ll>tnc,tc;
bool check(int g){
	if(g==0)
		return true;
	ll q=sqrt(g);
	if(q*q==g)
		return true;
	return false;
}
int main(){
 	cin>>n;
 	for(int i=0;i<n;i++){
		cin>>a[i];
		if(check(a[i])){
			cnt++;
	    	while(check(a[i]+mn[i])==true)
	    		mn[i]++;	
	    	tnc.pb(mn[i]);
	    }else{         
	    	ll q=sqrt(a[i]);
	    	tc.pb( min( abs( q*q-a[i] ) , abs( (q+1)*(q+1)-a[i] ) ) );
	    	cnt--;
	    }             
	}                         
	sort(tc.begin(),tc.end());
	sort(tnc.begin(),tnc.end());
	if(cnt==0){
		cout<<0;
		return 0;
	}
	if(cnt>0){
    	for(int i=0;i<cnt/2;i++)
    		ans+=tnc[i];
    }else{	
  		for(int i=0;i<-cnt/2;i++)
    		ans+=tc[i];
    }
    cout<<ans;
}