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
ll x,y,n,ans;
int main(){
    ios_base:: sync_with_stdio(false);
    cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q=i^j;
			if(q<=n && q>=j && q+i>j && q+j>i && i+j>q){
				//cout<<i<<" "<<j<<" "<<q<<endl;
				ans++;
			}
		}
	}
	cout<<ans;
}