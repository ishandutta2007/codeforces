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
const ll maxn=3e5+123,N=1e3,inf=1e9,mod=1e9+7;   
ll x,y,k,ans;
int main(){
    ios_base:: sync_with_stdio(false);
    cin>>x>>y;       
	if(y==1 && x>0){
		cout<<"NO";
		return 0;
	}              
	if(y!=0 && (x+y)%2==1 && x>=y-1 && (y-(x-1))%2==0)
		cout<<"Yes";
	else
		cout<<"No";
}