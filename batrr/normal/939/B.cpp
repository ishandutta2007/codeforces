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
const ll maxn=1e6+113,inf=1e9,INF=1e15+123,N=1e6,mod=1e9+7;
using namespace std;    
ll n,a[maxn],s,ans;
int main(){                             
	cin>>s>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=1;
	for(int i=2;i<=n;i++)
		if( s-s%a[i]>s-s%a[ans])
			ans=i;
	cout<<ans<<" "<<s/a[ans];    
}