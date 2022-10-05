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
int n,ans,x,y;
string s;
int main(){        
	cin>>n;   
	cin>>s;
	s=s+'&';
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='U')
			y++;
		else
			x++;
		if(x==y && s[i]==s[i+1])
			ans++;
	}
	cout<<ans;
}