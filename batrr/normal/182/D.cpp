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
const ll maxn=1e6+12,inf=2e9,mod=1e8; 
ull h[maxn],b=31,p[maxn];
set<ull> st;
string s;  
int ans,n;
ull geth(int l , int r){
	return h[r]-h[l-1]*p[r-l+1];
}
int main(){              
	cin>>s;                        
	n=s.size();
	s=' '+s;    
	p[0]=1;
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*b+(s[i]-'a'+1),p[i]=p[i-1]*b;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(geth(1,n-i)==geth(i+1,n))
				st.insert(geth(1,i));	
			if(i*i==n)
				break;
			if(geth(1,n-n/i)==geth(n/i+1,n))
				st.insert(geth(1,n/i));	
		}
	}
	cin>>s;                        
	n=s.size();
	s=' '+s;    
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*b+(s[i]-'a'+1),p[i]=p[i-1]*b;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(geth(1,n-i)==geth(i+1,n)){
				ans+= ( st.find(geth(1,i))!=st.end());
	//			cout<<i<<" ";
			}	
			if(i*i>=n)
				break;
			if(geth(1,n-n/i)==geth(n/i+1,n)){
				ans+= ( st.find(geth(1,n/i))!=st.end());	
	//			cout<<n/i<<" ";
			}
		}
	}	
	cout<<ans;
}