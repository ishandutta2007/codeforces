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
const ll maxn=1e5+123,inf=1e9,INF=1e18,N=1e6;
using namespace std;
ll k;
string ans="";
int main(){
	//IO
	cin>>k;

	if(k%2==1){
		ans+='4';
		k--;
	}
	while(k){
		k-=2;
		ans+='8';
	}
	if(ans.size()>18)
		cout<<-1;
	else
		cout<<ans;
}