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
const ll maxn=1e6+123,inf=1e9,INF=1e18,N=1e6,mod=95542721;
using namespace std;    
int n,a,b;
int main(){                 
	cin>>n>>a>>b;
	for(int x=0;x*a<=n;x++){
		if( (n-x*a)%b!=0 )
			continue;
		int y=(n-x*a)/b;
		int i=1;          
		while(x--){
			for(int j=1;j<a;j++)
				cout<<++i<<" ";
			i++;
			cout<<i-a<<" ";
		}
    	while(y--){
			for(int j=1;j<b;j++)
				cout<<++i<<" ";
			i++;
			cout<<i-b<<" ";
		}
		return 0;
	}
	cout<<-1;
}