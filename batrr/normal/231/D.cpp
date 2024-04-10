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
int a[7],ans,x,y,z,xx,yy,zz;
int main(){      
	cin>>x>>y>>z;
	cin>>xx>>yy>>zz;
	for(int i=1;i<=6;i++)
		cin>>a[i];
	if(y<0)
		ans+=a[1];
	if(y>yy)	
		ans+=a[2];
	if(z<0)
		ans+=a[3];
	if(z>zz)
		ans+=a[4];
	if(x<0)
		ans+=a[5];
	if(x>xx)
		ans+=a[6];
	cout<<ans;
}