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
const ll maxn=1002,inf=2e9,mod=1e9+7; 
set< pair < ull,ull> > st;
pair< ull, ull > h,b=mp(37,101);
string s,t;
int k,pre[2000],ans;
int main(){     
	cin>>s>>t>>k;
	for(int i=0;i<s.size();i++)
		pre[i]=pre[i-1]+(t[s[i]-'a']=='0');
	for(int i=0;i<s.size();i++){
		h=mp(0,0);
		for(int j=i;j<s.size();j++){
			h=mp(h.f*b.f+s[j]-'a'+1,h.s*b.s+s[j]-'a'+1);
			if(pre[j]-pre[i-1]<=k){
				st.insert(h);
				//cout<<i
			}
		}
	}
	cout<<st.size();
}