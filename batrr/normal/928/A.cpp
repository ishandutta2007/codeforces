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
  
#define nm "gcd" 
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
const ll maxn=2e5+123,N=2e5,inf=1e9,mod=1e9+7;
const ld eps=1e-12,PI=3.141592653589793238462643383279; 
int n;
string s,t;
char g( char a){      
	if(a=='_')
		return a;
	if(a>='1' && a<='9')
		return a;
	if(a=='o' || a=='O')
		return '0';
                   
	if(a=='l' || a=='L')
		return '1';
	
	if(a=='i' || a=='I')
		return '1';

	if(a>='A' && a<='Z')
		return a-'A'+'a';

	return a;
}
void check(string t){
	if(t.size()!=s.size())
		return;
	for(int i=0;i<s.size();i++){
		if( g(s[i])!=g(t[i]) )
			return;
	}
	cout<<"No";
	exit(0);
}
int main(){
	cin>>s>>n;
	while(n--){
		cin>>t;
		check(t);
	}
	cout<<"Yes";
}