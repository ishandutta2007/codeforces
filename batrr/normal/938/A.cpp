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
const ll maxn=1e5+13,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
ll n;
bool a[1000];
string s;
string get(string s){
	bool u=1;
	string res="a";
	res[0]=s[0];
	for(int i=1;i<s.size();i++){
		if(a[s[i]] && a[s[i-1]]){
			for(int j=i+1;j<s.size();j++)
				res+=s[j];
			return get(res);		
		}
		res+=s[i];
	}
	return s;
}
int main(){                
	cin>>n>>s;       
	a['a']=1;
	a['e']=1;
	a['i']=1;
	a['o']=1;
	a['u']=1;
	a['y']=1;
	cout<<get(s);
}