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
const int maxn=1e5+123,inf=2e9;  
ll a,b,la,lb,ans,cnt[10];
vector<int>v;
int main(){
	cin>>a>>b;
	ll g=a;                   
	while(g!=0)
		cnt[g%10]++,la++,g/=10;
    g=b;
	while(g!=0)
		lb++,g/=10;
    if(lb>la){
   		for(int i=9;i>=0;i--)
   			while(cnt[i]--)
   				cout<<i;
   		return 0;	
    }                  
    while(la--){
    //	cout<<ans<<endl;
    	for(int i=9;i>=0;i--){
    		if(cnt[i]==0)
    			continue;
    		cnt[i]--;
    		ll cur=ans*10+i;
    		for(int j=0;j<=9;j++){
    			int g=cnt[j];
    			while(g--)
    				cur=cur*10+j;	
    		}
    		if(cur>b){
    			cnt[i]++;
    			continue;
    		}
    		ans=ans*10+i;
   	 		break;    
   		}
   }
   cout<<ans;
}